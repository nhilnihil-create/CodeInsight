#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
 int n;cin>>n;
 int ans=0;
 for(int i=1;i<=n;i++)
 {
     int temp=n/i;
     int sum=(temp+1)*temp/2;
     ans+=i*sum;
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