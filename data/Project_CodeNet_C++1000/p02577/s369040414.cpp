#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  string s;
  cin>>s;
  int n=s.size(),i,j,k,l=0;
  for(i=0;i<n;i++)
  {
    l+=(s[i]-'0');
  }
  if(l%9==0) cout<<"Yes";
  else cout<<"No";
}