#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MODADD(ADD_X,ADD_Y)  (ADD_X+ADD_Y)%MOD;
#define MODSUB(SUB_X,SUB_Y)  (SUB_X-SUB_Y)+MOD)%MOD;
#define MODMUL(MUL_X,MUL_Y)  (MUL_X*MUL_Y)%MOD;
#define LCM(LCM_X,LCM_Y) (LCM_X*LCM_Y)/__gcd(LCM_X,LCM_Y);
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
int dx[]= {1,0,-1,0,1,-1,1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};
ll fact[MAX],inverse[MAX];
ll Bigmod(int a,int b)
{
    if(b==0)
        return 1%MOD;
    ll x=Bigmod(a,b/2);
    x=(x*x)%MOD;
    if(b%2==1)
        x=(x*a)%MOD;
    return x;
}
ll nCr(int x, int y)
{
    if(x<0 || y<0 || x<y)
        return 0;
    return (fact[x] * (inverse[y] * inverse[x - y] % MOD)%MOD) % MOD;
}
void pre_cal()
{

    fact[0]=1;
    for(int i=1; i<=5000; i++)
        fact[i]=(fact[i-1]*1LL*i)%MOD;
    inverse[5000]=Bigmod(fact[5000],MOD-2);
    for(int i=5000; i>0; i--)
    {
        inverse[i-1]=(i* 1LL*inverse[i] )% MOD;
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    int r=n-k;
    pre_cal();
    for(int i=1; i<=k; i++)
    {

        ll a=nCr(k-1,i-1);
        ll b=nCr(r+1,i);
        ll ans=(a*b)%MOD;

        cout<<ans<<endl;
    }
    return 0;
}
