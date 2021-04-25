#include<bits/stdc++.h>
using namespace std;
string hextobinary(char ch)
{unordered_map<char,int>mp;
mp={{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}};
string s;
s=bitset<4>(mp[ch]).to_string();
return s;
}
vector<int> consecutive_integers(string instruction)
{int n=instruction.size();
vector<int>vec;
for(int i=0;i<n;i++)
  {if(i+1<n)
    {if((isdigit(instruction[i]))&&(isdigit(instruction[i+1])))
       {vec.push_back((instruction[i+1]-'0')+(10*(instruction[i]-'0')));
       i++;}
     else if (isdigit(instruction[i]))
       vec.push_back(instruction[i]-'0');
       }
    else if(isdigit(instruction[i]))
       vec.push_back(instruction[i]-'0'); }
 return vec;
    }
vector<int> consecutive_integers_1(string instruction)
{int n=instruction.size(),p=0;
vector<int>vec;
for(int i=0;i<n;i++)
  {if(vec.size()<2)
  {if(i+1<n)
    {if((isdigit(instruction[i]))&&(isdigit(instruction[i+1])))
       {vec.push_back((instruction[i+1]-'0')+(10*(instruction[i]-'0')));
       i++;}
     else if (isdigit(instruction[i]))
       vec.push_back(instruction[i]-'0');
       }
    else if(isdigit(instruction[i]))
       vec.push_back(instruction[i]-'0'); }
    else if((vec.size()==2)&&(isdigit(instruction[i])))
      {
      p=i;
      break;
      }}
    vec.push_back(0);
  if (instruction[p-1]=='-')
  {
    vec.push_back(-1);
  }
  else
  {
    vec.push_back(0);
  }
  while((p<n)&&(isdigit(instruction[p])))
   {vec[2]=(10*vec[2])+(instruction[p]-'0');
   p++;
   }
 return vec;
    }
  vector<int> consecutive_integers_2(string instruction)
{int n=instruction.size(),p=0;
vector<int>vec;
for(int i=0;i<n;i++)
  {if(vec.size()<2)
  {if((isdigit(instruction[i]))&&(isdigit(instruction[i+1])))
       {vec.push_back((instruction[i+1]-'0')+(10*(instruction[i]-'0')));
       i++;}
     else if (isdigit(instruction[i]))
       vec.push_back(instruction[i]-'0');
       }
     else
     {
       break;
     }}
    return vec;}
    vector<int> consecutive_integers_3(string instruction)
{int n=instruction.size(),p=0;
vector<int>vec;
for(int i=0;i<n;i++)
  {if(vec.size()<1)
  {if((isdigit(instruction[i]))&&(isdigit(instruction[i+1])))
       {vec.push_back((instruction[i+1]-'0')+(10*(instruction[i]-'0')));
       i++;}
     else if (isdigit(instruction[i]))
       vec.push_back(instruction[i]-'0');
       }
     else
     {
       break;
     }}
    return vec;}
int main()
{string instruction;
vector<string>R={"add","sub","sll","slt","sltu","xor","srl","or","and","sra"};
vector<string>I={"addi","slli","slti","sltui","xori","ori","andi","jalr"};
vector<string>Ishift={"srlI","sraI"};
vector<string>Iload={"LB","LH","LW","LBU","LHU"};
vector<string>S={"SB","SH","SW"};
vector<string>U={"LUI","AUIPC"};
vector<string>SB={"beq","bne","bge","blt","bltu","bgeu"};
vector<string>UJ={"jal"};
while(getline(cin,instruction))
{string s2,s3,s4,s5,format;
s2=instruction.substr(0,2);
s3=instruction.substr(0,3);
s4=instruction.substr(0,4);
s5=instruction.substr(0,5);
if((find(I.begin(),I.end(),s2)!=I.end())||(find(I.begin(),I.end(),s3)!=I.end())||(find(I.begin(),I.end(),s4)!=I.end()))
    format="I";
else if((find(Iload.begin(),Iload.end(),s2)!=Iload.end())||(find(Iload.begin(),Iload.end(),s3)!=Iload.end())||(find(Iload.begin(),Iload.end(),s4)!=Iload.end()))
    format="Iload";
else if((find(Ishift.begin(),Ishift.end(),s2)!=Ishift.end())||(find(Ishift.begin(),Ishift.end(),s3)!=Ishift.end())||(find(Ishift.begin(),Ishift.end(),s4)!=Ishift.end()))
    format="Ishift";
else if((find(R.begin(),R.end(),s2)!=R.end())||(find(R.begin(),R.end(),s3)!=R.end())||(find(R.begin(),R.end(),s4)!=R.end()))
    format="R";
else if((find(S.begin(),S.end(),s2)!=S.end())||(find(S.begin(),S.end(),s3)!=S.end())||(find(S.begin(),S.end(),s4)!=S.end()))
    format="S";
else if((find(U.begin(),U.end(),s3)!=U.end())||(find(U.begin(),U.end(),s5)!=U.end()))
    format="U";
else if((find(SB.begin(),SB.end(),s3)!=SB.end())||(find(SB.begin(),SB.end(),s4)!=SB.end()))
    format="SB";
else if(find(UJ.begin(),UJ.end(),s3)!=UJ.end())
    format="UJ";
if(format=="R")
  {vector<int>vec;
vec=consecutive_integers(instruction);
int source1,source2,destination,opcode,func3,func7;
destination=vec[0];
source1=vec[1];
source2=vec[2];
opcode=51;
unordered_map<string,int>mp,mp1;
mp={{"add",0},{"sub",0},{"sll",1},{"slt",2},{"sltu",3},{"xor",4},{"srl",5},{"sra",5},{"or",6},{"and",7}};
mp1={{"add",0},{"sub",32},{"sll",0},{"slt",0},{"sltu",0},{"xor",0},{"srl",0},{"sra",32},{"or",0},{"and",0}};
if(find(R.begin(),R.end(),s2)!=R.end())
   {func3=mp[s2];
    func7=mp[s2];}
else if(find(R.begin(),R.end(),s3)!=R.end())
   {func3=mp[s3];
    func7=mp[s3];}
else if(find(R.begin(),R.end(),s4)!=R.end())
   {func3=mp[s4];
    func7=mp[s4];}
string src1,src2,dest,opc,fu3,fu7;
src1=bitset<5>(source1).to_string();
src2=bitset<5>(source2).to_string();
dest=bitset<5>(destination).to_string();
opc=bitset<7>(opcode).to_string();
fu3=bitset<3>(func3).to_string();
fu7=bitset<7>(func7).to_string();
cout<<fu7<<src2<<src1<<fu3<<dest<<opc;
}
else if(format=="I")
{vector<int>vec;
vec=consecutive_integers_1(instruction);
int source1,source2,immediate,opcode,func3,func7;
string dest;
source1=vec[0];
source2=vec[1];
immediate=vec[2];
opcode=19;
unordered_map<string,int>mp;
mp={{"addI",0},{"jalr",0},{"slli",1},{"slti",2},{"sltui",3},{"xori",4},{"ori",6},{"andi",7}};
if(find(I.begin(),I.end(),s2)!=I.end())
   {func3=mp[s2];
    }
else if(find(I.begin(),I.end(),s3)!=I.end())
   {func3=mp[s3];
    }
else if(find(I.begin(),I.end(),s4)!=I.end())
   {func3=mp[s4];
   if(s4=="jalr")
     opcode=103;
    }
 int flag = (int)log2(immediate)+1;
if(flag<12)
  {for(int i=0;i<flag;i++)
    {dest.push_back((immediate%2)+'0');
    immediate=immediate/2;}
  string temp;
  if(vec[3]==0)
    {for(int i=0;i<12-flag;i++)
       temp.push_back('0');
    temp.append(dest);}
  else
  {
     for(int i=0;i<12-flag;i++)
       temp.push_back('1');
     temp.append(dest);
  }
  dest=temp;
  }
else
{
  dest=bitset<12>(immediate).to_string();
}

string src1,src2,opc,fu3,fronti,backi;
src1=bitset<5>(source1).to_string();
src2=bitset<5>(source2).to_string();
opc=bitset<7>(opcode).to_string();
fu3=bitset<3>(func3).to_string();
cout<<dest<<src2<<fu3<<src1<<opc;
}
else if(format=="Ishift")
{vector<int>vec;
vec=consecutive_integers_1(instruction);
int source1,source2,immediate,opcode,func3,func7;
string dest;
source1=vec[0];
source2=vec[1];
immediate=vec[2];
opcode=19;
func3=5;
 int flag = (int)log2(immediate)+1;
if(flag<5)
  {for(int i=0;i<flag;i++)
    {dest.push_back((immediate%2)+'0');
    immediate=immediate/2;}
  string temp;
  if(vec[3]==0)
    {for(int i=0;i<5-flag;i++)
       temp.push_back('0');
    temp.append(dest);}
  else
  {
     for(int i=0;i<5-flag;i++)
       temp.push_back('1');
     temp.append(dest);
  }
  dest=temp;
  }
else
{
  dest=bitset<5>(vec[2]).to_string();
}
if(s4=="srlI")
  func7=0;
else
{
   func7=32;
}

string src1,src2,opc,fu3,fronti,backi,fu7;
src1=bitset<5>(source1).to_string();
src2=bitset<5>(source2).to_string();
opc=bitset<7>(opcode).to_string();
fu3=bitset<3>(func3).to_string();
fu7=bitset<7>(func7).to_string();
cout<<fu7<<dest<<src2<<fu3<<src1<<opc;
}
else if(format=="Iload")
{vector<int>vec;
vec=consecutive_integers_1(instruction);
int source1,source2,immediate,opcode,func3,func7;
string dest;
source1=vec[0];
source2=vec[1];
immediate=vec[2];
opcode=3;
unordered_map<string,int>mp;
mp={{"LB",0},{"LH",1},{"LW",2},{"LBU",4},{"LHU",5}};
if(s2=="LB"||s2=="LH"||s2=="LW")
   {func3=mp[s2];}
else
{
  func3=mp[s3];
}

 int flag = (int)log2(immediate)+1;
if(flag<12)
  {for(int i=0;i<flag;i++)
    {dest.push_back((immediate%2)+'0');
    immediate=immediate/2;}
  string temp;
  if(vec[3]==0)
    {for(int i=0;i<12-flag;i++)
       temp.push_back('0');
    temp.append(dest);}
  else
  {
     for(int i=0;i<12-flag;i++)
       temp.push_back('1');
     temp.append(dest);
  }
  dest=temp;
  }
else
{
  dest=bitset<12>(vec[2]).to_string();
}

string src1,src2,opc,fu3;
src1=bitset<5>(source1).to_string();
src2=bitset<5>(source2).to_string();
opc=bitset<7>(opcode).to_string();
fu3=bitset<3>(func3).to_string();
cout<<dest<<src2<<fu3<<src1<<opc;

}
else if(format=="S")
{vector<int>vec;
vec=consecutive_integers_1(instruction);
int source1,source2,immediate,opcode,func3;
string dest;
source1=vec[0];
source2=vec[1];
immediate=vec[2];
opcode=35;
unordered_map<string,int>mp;
mp={{"SB",0},{"SH",1},{"SW",2}};
func3=mp[s2];
int flag = (int)log2(immediate)+1;
if(flag<12)
  {for(int i=0;i<flag;i++)
    {dest.push_back((immediate%2)+'0');
    immediate=immediate/2;}
  string temp;
  if(vec[3]==0)
    {for(int i=0;i<12-flag;i++)
       temp.push_back('0');
    temp.append(dest);}
  else
  {
     for(int i=0;i<12-flag;i++)
       temp.push_back('1');
     temp.append(dest);
  }
  dest=temp;
  }
else
{
  dest=bitset<12>(vec[2]).to_string();
}

string src1,src2,opc,fu3,fronti,backi;
src1=bitset<5>(source1).to_string();
src2=bitset<5>(source2).to_string();
opc=bitset<7>(opcode).to_string();
fu3=bitset<3>(func3).to_string();
fronti=dest.substr(25,7);
reverse(fronti.begin(),fronti.end());
backi=dest.substr(12,5);
reverse(backi.begin(),backi.end());
cout<<fronti<<src2<<src1<<fu3<<backi<<opc;
}
else if(format=="U")
{int n,p=0;
n=instruction.size();
vector<string>vec;
int num;
for(int i=0;i<n;i++)
{if(isdigit(instruction[i])&&isdigit(instruction[i+1]))
     num=((instruction[i]-'0')*10)+(instruction[i+1]-'0');
else if(isdigit(instruction[i]))
     num=(instruction[i]-'0'); 
else if(instruction[i]=='X')
   {p=i+1;
   break;}
}
 while(instruction[p]!=';'&&p<n)
 {vec.push_back(hextobinary(instruction[p]));
 p++;}
 string immediate;
 if(vec.size()<8)
 {if(vec[0][0]=='1')
    {string set1;
    for(int i=0;i<(32-4*(vec.size()));i++)
     set1.push_back('1');
    for(auto it:vec)
     set1.append(it);
    immediate=set1;
    }
  else if(vec[0][0]=='0')
   {string set1;
   for(int i=0;i<(32-4*(vec.size()));i++)
     set1.push_back('0');
    for(auto it:vec)
     set1.append(it);
    immediate=set1;}}
 else
 { immediate="";
     for(auto it:vec)
      immediate.append(it);
 }
 
 string h,imm,opcode;
 if(s3=="LUI")
   opcode="0110111";
 else
 {
    opcode="0010111";
 }
 
 h=bitset<5>(num).to_string();
 imm=immediate.substr(12,20);
 cout<<imm<<h;  
}
else if(format=="SB")
{vector<int>vec;
vec=consecutive_integers_2(instruction);
int source1,source2,immediate,opcode,func3,func7;
string dest;
source1=vec[0];
source2=vec[1];
opcode=99;
unordered_map<string,int>mp;
mp={{"beq",0},{"bne",1},{"bge",5},{"blt",4},{"bltu",6},{"bgeu",7}};
if(find(I.begin(),I.end(),s3)!=I.end())
   {func3=mp[s3];
    }
else if(find(I.begin(),I.end(),s4)!=I.end())
   {func3=mp[s4];
    }
int p=0;
while(instruction[p]!='X')
{p++;}
p++;
dest="";
while(instruction[p]!=';'&&p<instruction.size())
{dest.append(hextobinary(instruction[p]));
p++;}
if(dest.size()<32)
{string temp;
for(int i=0;i<(32-dest.size());i++)
  temp.push_back(dest[0]);
temp.append(dest);
dest=temp;}
string src1,src2,opc,fu3,des1,des2,des3,des4;
des1=dest.substr(20,1);
des2=dest.substr(22,6);
reverse(des2.begin(),des2.end());
des3=dest.substr(28,4);
reverse(des3.begin(),des3.end());
des4=dest.substr(21,1);
src1=bitset<5>(source1).to_string();
src2=bitset<5>(source2).to_string();
opc=bitset<7>(opcode).to_string();
fu3=bitset<3>(func3).to_string();
cout<<des1<<des2<<src2<<src1<<fu3<<des3<<des4<<opc;}
else if(format=="UJ")
{vector<int>vec;
vec=consecutive_integers_3(instruction);
int source1,immediate,opcode;
string dest;
source1=vec[0];
opcode=111;
int p=0;
while(instruction[p]!='X')
{p++;}
p++;
dest="";
while(instruction[p]!=';'&&p<instruction.size())
{dest.append(hextobinary(instruction[p]));
p++;}
if(dest.size()<32)
{string temp;
for(int i=0;i<(32-dest.size());i++)
  temp.push_back(dest[0]);
temp.append(dest);
dest=temp;}
string src1,src2,opc,fu3,des1,des2,des3,des4;
des1=dest.substr(12,1);
des2=dest.substr(22,10);
reverse(des2.begin(),des2.end());
des3=dest.substr(21,1);
des4=dest.substr(13,8);
reverse(des4.begin(),des4.end());
src1=bitset<5>(source1).to_string();
opc=bitset<7>(opcode).to_string();
cout<<des1<<des2<<des3<<des4<<src1<<opc;}
cin.ignore();
}
}
