/************************************Tufaan************************************/
#include<bits/stdc++.h>
#define pi acos(-1.0)
#define pb push_back
#define LL long long
#define LIM 50000
#define dbg(x) cout<<#x<<" = "<<x<<'\n';
using namespace std;
int _I(){int x; scanf("%d",&x); return x;}
LL _L(){LL x; scanf("%lld",&x); return x;}
LL gcd(LL a, LL b){ while(b) b ^= a ^= b ^= a %= b; return a; }
LL lcm(LL x,LL y){x/=gcd(x,y); return x*y;}
int kdx[8]={-2,-2,-1,-1,1,1,2,2};
int kdy[8]={-1,1,-2,2,-2,2,-1,1};
bool prime[LIM+7];
long long _pow(long long a, long long b){
        if(b == 0) return 1;
        long long ret = 1;
        ret *= _pow(a, b/2);
        ret = ret*ret;
        if(b&1){
                ret *= a;
        }
        return ret;
}
bool inrng(LL x, LL y, LL c){
        return (x <= c && c <= y);
}
bool inRng(int a, int b, int x, int y){
        return ( inrng(a,b,x) || inrng(a,b,y) || inrng(x,y,a) || inrng(x,y,b) );
}
vector<int> v;
map<int, int> mp;
void sieve(){
    int i,j; prime[1]=1; v.pb(2);
    for(i=4;i<=LIM;i+=2) prime[i]=1;
    for(i=3;i<=LIM;i+=2) if(!prime[i]){ v.pb(i); for(j=i+i+i;j<=LIM;j+=i+i) prime[j]=1;}
}

/********************************************************************************/
/********************************************************************************/
int cases;

void fun(){
        int n,k,mn,mx;
        n = _I();
        k = _I();
        if(k == 1) puts("0");
        else {
                printf("%d\n",n-k);
        }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //sieve();
    //int t = _I();
    //while(t--)
        fun();
    return 0;
}
