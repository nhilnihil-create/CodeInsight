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
    return fact[x] * (inverse[y] * inverse[x - y] % MOD) % MOD;
}
void pre_cal()
{

    fact[0]=1;
    for(int i=1; i<=MAX; i++)
        fact[i]=fact[i-1]*1LL*i%MOD;
    inverse[MAX]=Bigmod(fact[MAX],MOD-2);
    for(int i=MAX; i>0; i--)
    {
        inverse[i-1]=i* 1LL*inverse[i] % MOD;
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    pre_cal();
    int x,y;
	cin>>x>>y;
	int a = (2*x-y)/3, b = (2*y-x)/3;
	if( (a<0) || (b<0) || (2*a+b != x) || (2*b+a != y) ) {
        cout<<"0"<<endl;
	}
	else
	cout<<nCr(a+b,a)<<endl;;

    return 0;
}
