/*

 Remember, Hope is a good thing... May be the best of things... and No Good thing ever Dies !!!

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007
#define MOD1 1e18
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
typedef long double ld;
const ll inf=(1LL<<60)-1;
const ll mxn=1e5;
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
long long ans,a[100005];
ll mod(ll x)
{
    ll res=x%MOD;
    while(res<0)
        res+=MOD;
    return res;
}
ll bigmod(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1)
            res=res*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}
void solve()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;
    ll ans=mod(bigmod(10,n)-bigmod(9,n)-bigmod(9,n)+bigmod(8,n));
    ans=(ans+MOD)%MOD;
    cout<<ans<<endl;
}
int main()
{
    IOS;
    //ll t;
    //cin>>t;
    // while(t--)
    solve();
    return 0;
}
