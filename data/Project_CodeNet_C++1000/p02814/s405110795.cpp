#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
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
#define sz(x) long long(x.size())

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

const ll INF = 1e9+10;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll ngcd(vector<ll> a) {
  ll res = a[0];
  for(ll i=1; i<a.size() && res!=1; i++) res = gcd(a[i], res);
  return res;
}
ll nlcm(vector<ll> a){
  ll res = a[0];
  for(ll i=1; i<a.size(); i++) res = lcm(a[i], res);
  return res;
}
bool is_prime(ll n) {
  if(n < 2) return false;
  for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
  return true;
}
ll digsum(ll n) {
  ll res=0;
  while(n) res += n%10, n /= 10;
  return res;
}
ll digcnt(ll n){
  ll res=0;
  while(n) res++, n /= 10;
  return res;
}
vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}
map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) ++res[i], n /= i;
  }
  if (n != 1) res[n] = 1;
  return res;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll n,m; cin>>n>>m;
  vll a(n);
  rep(i,n) cin>>a[i];
  
  rep(i,n) a[i]/=2;
  
  ll two=1;
  while(a[0]%2==0) two*=2, a[0]/=2;
  
  irep(i,1,n){
    ll tmp=1;
    while(a[i]%2==0) tmp*=2, a[i]/=2;
    if(two!=tmp){
      cout<<0<<endl;
      return 0;
    }
  }
  
  if(two) m/=two;
  ll l=1;
  rep(i,n){
    l=lcm(l,a[i]);
    if(l>m){
      cout<<0<<endl;
      return 0;
    }
  }
  
  // cout<<l<<' '<<m<<endl;
  ll ans=m/l-(m/l)/2;
  cout<<ans<<endl;
  
}