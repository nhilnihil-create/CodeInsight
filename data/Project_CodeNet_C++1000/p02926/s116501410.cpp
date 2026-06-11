//#include <bits/stdc++.h>
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

#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define ALL(x) x.begin(),x.end()
#define mst(var,val) memset(var,val,sizeof(var))
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ls rt<<1
#define rs rt<<1|1
#ifdef local
#define dbg(a) cout << #a": " << a << endl;
#else
#define dbg(a)
#endif // loacl


using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <double, double> pdd;
const ll inf=0x3f3f3f3f;
const long long INF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const long double eps=1e-6;
const int mod=1e9+7;
const int maxn=20;
const int N=1e5+10;
const int M=N<<1;
const ll mm=(1LL<<32);

template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}
ll qpow(ll a,ll b,ll MOD)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%MOD;
        b>>=1;
        a=(a*a)%MOD;
    }
    return ans;
}


struct Point{
    int x,y;
}p[105];
bool cmp(const Point &a,const Point &b)
{
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}
int nx[105];
int main()
{
#ifdef local
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif // local
    IOS;
    int n;cin>>n;
    rep1(i,n) cin>>p[i].x>>p[i].y;
    rep1(i,n) nx[i]=i+1;nx[n]=1;
    sort(p+1,p+1+n,cmp);
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
        ll x=p[i].x,y=p[i].y;
        ans=max(ans,x*x+y*y);
        for(int j=nx[i];j!=i;j=nx[j])
        {
            x+=p[j].x;y+=p[j].y;
            ans=max(ans,x*x+y*y);
        }
    }
    double sum=1.0*sqrt(ans);
    printf("%.10f\n",sum);
    return 0;
}

