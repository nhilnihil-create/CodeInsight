#include <bits/stdc++.h>
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define show(x) cout << #x << " = " << (x) << endl
#define show2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define show3(x,y,z) cout << #x << " = " << (x) << ", " << #y << " = " << (y) <<  ", " << #z << " = " << (z) << endl
#define showv(v) rep(i,v.size()) printf("%d%c", v[i], i==v.size()-1?'\n':' ')
#define showv2(v) rep(j,v.size()) showv(v[j])
#define showt(t,n) rep(i,n) printf("%d%c", t[i], i==n-1?'\n':' ')
#define showt2(t,r,c) rep(j,r) showt(t[j],c)
#define showvp(p) rep(i,p.size()) printf("%d %d\n", p[i].first, p[i].second)
#define showmp(mp) for (auto p:mp) printf("%d %d\n", p.first, p.second)
#define printv(v) rep(i,v.size()) printf("%d\n", v[i])
#define printt(t,n) rep(i,n) printf("%d\n", t[i])
#define incl(v,x) (find(all(v),x)!=v.end())
#define incls(s,c) (s.find(c)!=string::npos)
#define lb(a,x) distance((a).begin(),lower_bound(all(a),(x)))
#define ub(a,x) distance((a).begin(),upper_bound(all(a),(x)))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define bit(n,k) ((n>>k)&1) // nのk bit目
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define uni(x) x.erase(unique(all(x)),x.end())
#define SP << " " <<
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using vp = vector<P>;
using vt = vector<T>;
const int mod = 1000000007;
const double EPS = 1e-9;
//const long double EPS = 1e-14;
const int INF = (1<<30)-1;
const ll LINF = (1LL<<62)-1;
#define dame { puts("No"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define YN {puts("YES");}else{puts("NO");}
inline int in() { int x; cin >> x; return x;}
inline ll lin() { ll x; cin >> x; return x;}
inline char chin() { char x; cin >> x; return x;}
inline string stin() { string x; cin >> x; return x;}
inline double din() { double x; cin >> x; return x;}
//template<class T = int> inline T in() { T x; cin >> x; return (x);}
template<typename T>inline ll suma(const vector<T>& a) { ll res(0); for (auto&& x : a) res += x; return res;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
char itoa(int n) { return n + '0';}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
const int dy[4] = {0, -1,  0,  1};
const int dx[4] = {1,  0, -1,  0};

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p,y);
    }
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
};
/*
int main () {
  Sieve sieve(50);
  // 素数列挙
  vi p = sieve.primes;
  showv(p);
  newline;
  // 素数判定
  rep(i,51) show2(i,sieve.isPrime(i));
  newline;
  // 素因数分解
  vp factor = sieve.factor(45);// [(3,2),(5,1)] 3^2*5^1
  showvp(factor);
  return 0;
}
*/

int main () {
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];

  Sieve sieve(*max_element(all(a)));
  map<int, int> mp;
  rep(i,n) {
    vp factor = sieve.factor(a[i]);
    for (auto p : factor) {
      mp[p.fi]++;
    }
  }

  bool pairwise = true;
  for (auto p : mp) {
    if (p.se >= 2) pairwise = false;
  }
  
  if (pairwise) {
    puts("pairwise coprime");
    return 0;
  }

  int gcd_all = 0;
  rep(i,n) gcd_all = gcd(gcd_all, a[i]);
  if (gcd_all == 1) {
    puts("setwise coprime");
    return 0;
  }
  else {
    puts("not coprime");
    return 0;
  }
  
  return 0;
}