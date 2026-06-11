//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize(4)
//#pragma GCC optimize("unroll-loops")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
//#include <bits/extc++.h>
#define fi first
#define se second
#define db double
#define mp make_pair
#define pb push_back
#define mt make_tuple
//#define pi acos(-1.0)
#define ll long long
#define vi vector<int>
#define mod 998244353
#define ld long double
//#define C 0.5772156649
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define ull unsigned long long
#define bpc __builtin_popcount
#define base 1000000000000000000ll
#define fin freopen("a.txt","r",stdin)
#define fout freopen("a.txt","w",stdout)
#define fio ios::sync_with_stdio(false);cin.tie(0)
#define mr mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline void sub(ll &a,ll b){a-=b;if(a<0)a+=mod;}
inline void add(ll &a,ll b){a+=b;if(a>=mod)a-=mod;}
template<typename T>inline T const& MAX(T const &a,T const &b){return a>b?a:b;}
template<typename T>inline T const& MIN(T const &a,T const &b){return a<b?a:b;}
inline ll mul(ll a,ll b,ll c){return (a*b-(ll)((ld)a*b/c)*c+c)%c;}
inline ll qp(ll a,ll b){ll ans=1;while(b){if(b&1)ans=ans*a%mod;a=a*a%mod,b>>=1;}return ans;}
inline ll qp(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=mul(ans,a,c);a=mul(a,a,c),b>>=1;}return ans;}

using namespace std;
//using namespace __gnu_pbds;

const ld pi = acos(-1);
const ull ba=233;
const db eps=1e-5;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=200000+10,maxn=2000000+10,inf=0x3f3f3f3f;

priority_queue<pii>q;
int a[N],b[N];
int main()
{
    int n;scanf("%d",&n);
    ll sum=0;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)scanf("%d",&b[i]),q.push(mp(b[i],i));
    while(!q.empty())
    {
        int x=q.top().se;q.pop();
        if(b[x]<a[x])return 0*puts("-1");
        else if(b[x]>a[x])
        {
            int te=b[(x-1+n)%n]+b[(x+1)%n];
            if(b[x]-a[x]<te)return 0*puts("-1");
            sum+=(b[x]-a[x])/te;
            b[x]-=(b[x]-a[x])/te*te;
            q.push(mp(b[x],x));
        }
    }
    printf("%lld\n",sum);
    return 0;
}
/********************

********************/
