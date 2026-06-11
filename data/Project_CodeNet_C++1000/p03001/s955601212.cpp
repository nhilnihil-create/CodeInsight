#include <bits/stdc++.h>
#include <fstream>
#include<string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N=2e5+5;
ll mod=1e9+7;
ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);
    ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}


int main()
{
    FIO
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    ld ans=(ld)(a*b)/2.0;
    bool good=((((a)/2)==x)&&((b)/2==y)&&(a%2==0)&&(b%2==0));
    cout<<fixed<<setprecision(12)<<ans<<" ";
    cout<<good<<endl;
    return 0;
}