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
ll power(ll x,ll y){ll res=1; while(y>0){if(y&1) res=(res*x)%MOD;y=y>>1;x=(x*x)%MOD;}return res%MOD;} // modular exponent
ll inv(ll x)
{
  return power(x,MOD-2);
}
int main()
{
    ios_base::sync_with_stdio(false); // don't use printf and scanf
    cin.tie(NULL); // cout<<fixed<<setprecision
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans=power(2,n);
    ans-=1ll;
    ans+=MOD;
    ans%=MOD;
    // calculate product x and y;
    ll x=1ll;
    repA(i,n-a+1,n)
    {
      x*=i;
      x%=MOD;
    }
    ll y=1ll;
    repA(i,1,a)
    {
      y*=i;
      y%=MOD;
    }
    y=inv(y);
    ans-=((x*y)%MOD);
    ans+=MOD;
    ans%=MOD;
    x=1ll;
    repA(i,n-b+1,n)
    {
      x*=i;
      x%=MOD;
    }
    y=1ll;
    repA(i,1,b)
    {
      y*=i;
      y%=MOD;
    }
    y=inv(y);
    ans-=((x*y)%MOD);
    ans+=MOD;
    ans%=MOD;
    cout<<ans<<'\n';
    return 0;
}
// JUST ASK YOURSELF DID YOU GIVE YOUR BEST ? ISSE ZYADA
// KUCH KAR BHI NAHI SAKTE !! ENJOY AND GIVE YOUR BEST!!
