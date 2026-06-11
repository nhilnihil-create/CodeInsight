#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      swap(a,b)        {a=a+b;b=a-b;a=a-b;}
#define      rep(i, n)         for(ll i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(ll i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(ll i = a; i >= (n); --i)
#define watch(x) cout << (#x) << " is " << (x) <<endl

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
ll power(ll x,ll y){ll res=1; while(y>0){if(y&1) res=res*x;y=y>>1;x=x*x;}return res;} // modular exponent
ll h,n;
const int maxn=1e4+4;
ll dp[maxn];
ll a[maxn],b[maxn];
const ll inf=1e9;
int main()
{
    ios_base::sync_with_stdio(false); // don't use printf and scanf
    cin.tie(NULL); // cout<<fixed<<setprecision
    cin>>h>>n;
    repA(i,1,n)
    {
      cin>>a[i]>>b[i];
    }
    dp[0]=0ll;
    for(ll i=1;i<=h;i++)
    {
      ll ans=inf;
      for(ll k=1;k<=n;k++)
      {
        if(i-a[k]<=0) ans=min(ans,b[k]);
        else ans=min(ans,b[k]+dp[i-a[k]]);
      }
      dp[i]=ans;
    }
    cout<<dp[h]<<'\n';
    return 0;
}
// JUST ASK YOURSELF DID YOU GIVE YOUR BEST ? ISSE ZYADA
// KUCH KAR BHI NAHI SAKTE !! ENJOY AND GIVE YOUR BEST!!
