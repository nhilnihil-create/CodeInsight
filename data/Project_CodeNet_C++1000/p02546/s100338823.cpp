#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int last=s.length()-1;
  if(s[last]=='s')
  s+="es";
  else
  s+="s";;
  cout<<s<<endl;
}
