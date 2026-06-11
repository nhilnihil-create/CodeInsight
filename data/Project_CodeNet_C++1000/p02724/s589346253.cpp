#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define mod 1000000007



void solve()
{
    int x;cin>>x;
    int f=x/500;
    x=x%500;
    int ans=f*1000;
    int s=x/5;
    ans+=s*5;
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
    return 0;
}

