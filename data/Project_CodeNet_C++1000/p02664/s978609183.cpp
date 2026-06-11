#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int n=s.length(),i;
  for(i=0;i<n;i++)
    if(s[i]=='?')
      s[i]='D';
  cout<<s;
  return 0;
}