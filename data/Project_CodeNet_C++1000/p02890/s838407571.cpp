//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
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
#define mod 1000000007
#define ld long double
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
#define mr mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline void sub(ll &a,ll b){a-=b;if(a<0)a+=mod;}
inline void add(ll &a,ll b){a+=b;if(a>=mod)a-=mod;}
inline ll mul(ll a,ll b,ll c){return (a*b-(ll)((ld)a*b/c)*c+c)%c;}
inline ll qp(ll a,ll b){ll ans=1;while(b){if(b&1)ans=ans*a%mod;a=a*a%mod,b>>=1;}return ans;}
inline ll qp(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=mul(ans,a,c);a=mul(a,a,c),b>>=1;}return ans;}

using namespace std;
//using namespace __gnu_pbds;

const ld pi = acos(-1);
const ull ba=233;
const db eps=1e-8;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=300000+10,maxn=1000000+10,inf=0x3f3f3f3f;

int a[N],b[N],c[N];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<=n;i++)b[a[i]]+=a[i],c[a[i]]++;
    for(int i=1;i<=n+1;i++)b[i]+=b[i-1],c[i]+=c[i-1];
    auto ok=[&](int l,int k)
    {
        return (c[n]-c[k])*k+b[k]>=l*k;
    };
    int ans=n+1;
    for(int i=1;i<=n;i++)
    {
        while(ans&&!ok(i,ans))ans--;
        printf("%d\n",ans);
    }
    return 0;
}
/********************

********************/
