#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define pb emplace_back
#define f first
#define s second
#define rep(i, st, ed) for(ll i=st; i<ed; ++i)
#define repn(i, st, ed) for(ll i=st; i<=ed; ++i)
#define repb(i, ed, st) for(ll i=ed; i>=st; --i)
#define all(v) v.begin(),v.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define PI acosl(-1.0)
#define mp(a, b) make_pair(a, b)
#define eps 1e-9
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
const int N = 1e5 + 10;
const ll INF = 1LL << 60;
ll iv[N];
ll powM(ll a, ll b){ll res = 1;for(;b;a=a*a%M,b/=2) if(b&1) res=res*a%M;return res;}
ll nckbig(int n, int k){ll ans = 1;for(int i=1; i<=k; ++i){ans = ans*(n-i+1)%M*iv[i]%M;}return ans;}
ll caliv(){iv[1] = 1;for(int i=2; i<N; i++){iv[i] = M-M/i*iv[M%i]%M;}}
ll f1[N], f2[N];
ll calf(){f1[0] = f2[0] = 1;for(int i=2; i <N; ++i){f1[i] = f1[i-1]*i%M;f2[i] = f2[i-i]*iv[i]%M;}}
ll nck(int n, int k){return f1[n]*f2[n-k]%M*f2[k]%M;}
ll npk(int n, int k){return f1[n]*f2[n-k]%M;}
ll Rnck(int big){if(big){caliv();}else{calf();}}

void solve()
{
  int k, q;
  cin>>k>>q;
  vector<ll> v(k);
  rep(i, 0, k) cin>>v[i];
  while(q--){
    ll n, x, m;
    cin>>n>>x>>m;
    ll s1 = 0, s2=0;
    rep(i, 0, k){
      ll tmp = v[i]%m;
      if(!tmp) tmp = m;
      if((n-1)%k > i) s2 += tmp;
      s1 += tmp;
    }
    ll x2 = x + (n-1)/k*s1 + s2;
    cout<<(n-1-(x2/m-x/m))<<endl;
  }
}


int main()
{
    FAST
    ll Tests = 1;
    //cin>>Tests;
    while(Tests--)
    {
        solve();
    }
    return 0;
}