#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
    int a;int b;cin>>a>>b;
    int ans=a-(2*b);
    if(ans<0)
    ans=0;
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