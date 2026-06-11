#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<cstring>
#include<bitset>
#include<stack>
#include<time.h>



#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define ALL(x) x.begin(),x.end()
#define sz(a) ((int)a.size())
#define getmid ((l+r)>>1)
#define mst(var,val) memset(var,val,sizeof(var))
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define lowbit(x) x&(-x)
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
#ifdef local
#define dbg(args...) cout << #args << " -> ", err(args);
void err(){ cout << endl; }
template<typename T, typename... Args>
void err(T a, Args... args){ cout << a << ' '; err(args...); }
#else
#define dbg(args...)
#endif // local

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <double, double> pdd;
const int inf=0x3f3f3f3f;
const long long INF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const long double eps=1e-8;
const int mod=1e9+7;
const int maxn=3e5+100;
const int N=1e6+1000;
const int M=500+10;
const ll mm=(1LL<<32);

template <class T>
inline void read(T &x)
{
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar())
        f ^= c == '-';
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10)
        ++len;
    for (; len; --len, x %= y, y /= 10)
        putchar(x / y + 48);
}
ll qpow(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

int vis[N],a[N];
int tot,prime[N];
void init()
{
    for(int i=2;i<N;++i)
    {
        if(!vis[i]) prime[tot++]=i;
        for(int j=0;j<tot;++j)
        {
            if(i*prime[j]>N) break;
            vis[i*prime[j]]=1;
        }
    }
}
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
#ifdef local
    freopen("in.txt","r",stdin);
#endif // local
    //IOS;cout.tie(0);
    init();
    int n;read(n);
    rep1(i,n) read(a[i]);
    int flag=1,tag=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==1)
        {
            tag=1;continue;
        }
        int x=a[i];
        for(int j=0;j<tot&&prime[j]*prime[j]<=x;++j)
        {
            if(x%prime[j]==0)
            {
                while(x%prime[j]==0) x/=prime[j];
                if(vis[prime[j]]!=0)
                {
                    flag=0;break;
                }
                else vis[prime[j]]=1;
            }
        }
        if(x!=1)
        {
            if(vis[x]==1) flag=0;
            else vis[x]=1;
        }
        if(!flag) break;
    }
    if(flag)
    {
        puts("pairwise coprime");
        return 0;
    }
    int ans=a[1];
    for(int i=2;i<=n;++i) ans=gcd(ans,a[i]);
    if(ans==1) puts("setwise coprime");
    else puts("not coprime");
    return 0;
}
