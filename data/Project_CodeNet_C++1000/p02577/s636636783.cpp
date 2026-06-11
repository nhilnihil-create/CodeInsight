#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int sum =0;
  for(int i=0;i<s.length();i++)
  {
    sum = (sum%9+(s[i]-'0'))%9;
  }
  if(sum%9 == 0) cout<<"Yes\n";
  else cout<<"No\n";
  return 0;
}