#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define int long long int
typedef complex<long double> cd;
const long double pi=acos(-1);
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector<vector<int> > matrix;

#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))

#define fi first
#define se second
#define endl "\n"
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>

inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p%m*p%m)%m;if(n%2) return (p%m*a%m)%m;else return p;}
const ll MOD =998244353;
const ll hell=1000000007;
const int INF = 1e17;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

const int N=100005;

void solve()
{
   int h,w,m;
   cin>>h>>w>>m;
   set<pair<int,int>>s;int x,y;
   int cnt1[h+1]={0},cnt2[w+1]={0};
   for(int i=0;i<m;i++)
   {
       cin>>x>>y;
       s.insert(m1(x,y));
       cnt1[x]++;
       cnt2[y]++;
   }
   int mxr=0,mxc=0;
   for(int i=1;i<=h;i++)
   mxr=max(mxr,cnt1[i]);
   for(int i=1;i<=w;i++)
   mxc=max(mxc,cnt2[i]);
   vi rw,cl;
   for(int i=1;i<=h;i++)
   {
       if(cnt1[i]==mxr)
       rw.pb(i);
   }
   for(int i=1;i<=w;i++)
   {
       if(cnt2[i]==mxc)
       {
           cl.pb(i);
       }
   }
   int ans=cnt1[rw[0]]+cnt2[cl[0]];
   if(s.find(m1(rw[0],cl[0]))!=s.end())
   ans--;
   else
   {
       cout<<ans<<endl;
       return;
   }
   
   for(int i:rw)
   {
       for(int j:cl)
       {
           if(s.find(m1(i,j))==s.end())
           {
               cout<<ans+1<<endl;
               return;
           }
       }
   }
   cout<<ans<<endl;
   


    
}
int32_t main()
{
    IOS;
    //FILE *fin = freopen("in","r",stdin);
    //FILE *fout = freopen("out","w",stdout);
    int t;
    t=1;
   // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}



