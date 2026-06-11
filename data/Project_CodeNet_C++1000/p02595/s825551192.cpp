#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
   int n;int d;cin>>n>>d;
   int ans=0;
   for(int i=1;i<=n;i++)
   {
       int x;int y;cin>>x>>y;
       int dist=x*x + y*y;
       if(dist<=(d*d))
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