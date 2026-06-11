#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    (a *= a) %= MOD;
    n >>= 1;
  }
  return res;
}

const ll maxf = 10000000;
ll fact[maxf+5];

void fact_init(){
  fact[0] = 1;
  for(ll i=1; i<=maxf; i++){
    fact[i] = (fact[i-1] * i) % MOD;
  }
}

ll comb(ll a, ll b){
  if(a<b || a<0 || b<0) return 0;
  if(fact[0] == 0) fact_init();
  return (fact[a] * modpow((fact[a-b]*fact[b])%MOD, MOD-2)) % MOD;
}


signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n,k; cin>>n>>k;
  vll a(n);
  rep(i,n) cin>>a[i];
  ll p=0;
  rep(i,n) irep(j,i+1,n) if(a[i]>a[j]) p++;
  ll q=0;
  rep(i,n) rep(j,n) if(a[i]>a[j]) q++;
  p=(p*k)%MOD;
  q=k*(k-1)%MOD*modpow(2,MOD-2)%MOD*q%MOD;
  cout<<(p+q)%MOD<<endl;
}