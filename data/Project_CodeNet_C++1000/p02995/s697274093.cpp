#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll ADD(ll ADD_X,ll ADD_Y)
{
    return (ADD_X+ADD_Y)%MOD;
}
ll SUB(ll SUB_X,ll SUB_Y)
{
    return ((SUB_X-SUB_Y)+MOD)%MOD;
}
ll LCM(ll LCM_X,ll LCM_Y)
{
    return (LCM_X*LCM_Y)/__gcd(LCM_X,LCM_Y);
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll lcm=LCM(c,d);
    ll y=b/c - (a-1)/c;
    ll x=b/d - (a-1)/d;
    ll cm=b/lcm - (a-1)/lcm;
    ll ans=x+y-cm;
    ll range=(b-a)+1;
    ans=range-ans;
    cout<<ans<<endl;

    return 0;
}
