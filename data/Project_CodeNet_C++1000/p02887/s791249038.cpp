#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll n,i;
  cin>>n;
  string str;
  cin>>str;
  ll ans=1;
  for(i=1; i<n; i++)
  {
    if(str[i]!=str[i-1])
      ans++;
  }
  cout<<ans<<'\n';
  return 0;
}