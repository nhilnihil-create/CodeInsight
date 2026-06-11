#include<iostream>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int i=0;
  if(s[i]=='R'&& s[i+1]=='R'&& s[i+2]=='R')
    cout<<3<<endl;
  else if((s[i]=='R' && s[i+1]!='R' && s[i+2]!='R') || (s[i]!='R' && s[i+1]=='R' && s[i+2]!='R') || (s[i]=='R' && s[i+1]!='R' && s[i+2]=='R')||(s[i]!='R' && s[i+1]!='R' && s[i+2]=='R'))
     cout<<1<<endl;
	else if((s[i]=='R' && s[i+1]=='R' && s[i+2]!='R') || (s[i]!='R' && s[i+1]=='R' && s[i+2]=='R'))
      cout<<2<<endl;
  else
    cout<<0<<endl;
  return 0;
}





































































