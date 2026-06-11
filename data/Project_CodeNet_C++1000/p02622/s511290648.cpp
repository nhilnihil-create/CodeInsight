#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
  string s;string t;cin>>s>>t;
  int ans=0;
  for(int i=0;i<s.size();i++)
  {
      if(s[i]!=t[i])
      ans++;
  }
  cout<<ans<<endl;
    
}
int32_t main()
{
    rapido;
    int t;
    //cin>>t;
      t=1;
    while(t--)
    solve();
}