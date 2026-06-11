#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int c=0;
  if(s[0]=='R' && s[1]=='R' && s[2]=='R')
    c=3;
  else if(s[0]=='R' && s[1]=='R' || s[1]=='R' && s[2]=='R')
    c=2;
  else if(s[0]=='R' || s[1]=='R' ||s[2]=='R')
    c=1;
  else
    c=0;
  cout<<c<<endl;
}
      