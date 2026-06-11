#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

#ifdef _DEBUG
inline void dump() { cerr << endl; }
template<typename Head> void dump(Head&& head) { cerr << head; dump(); }
template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }
#define debug(...) do {cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)
#else
#define dump(...)
#define debug(...)
#endif

template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////

const ll inf = 1LL<<60;
const ll mod = 1000000007;

ll modinv(ll a, ll m)
{
  ll b=m, x=1, y=0;
  while (b) {
    ll t = a/b;
    a -= t*b; swap(a, b);
    x -= t*y; swap(x, y);
  }
  x %= m;
  if (x<0) x += m;
  return x;
}

ll choose(ll n, ll r, ll p)
{
  ll ret = 1;
  while(true) {
    if (r==0) break;
    ll N = n%p;
    ll R = r%p;
    if (N<R) return 0;
    for (ll i=0; i<R; i++) {
      ret = ret * (N-i) % p;
    }
    ll imul = 1;
    for (ll i=0; i<R; i++) {
      imul = imul * (i+1) % p;
    }
    ret = ret * modinv(imul, p) % p;
    n /= p;
    r /= p;
  }
  return ret;
}

ll modpow(ll a, ll n)
{
  ll res=1;
  while (n>0) {
    if (n&1) res = res*a % mod;
    a = a*a % mod;
    n >>= 1;
  }
  return res;
}

int main()
{
  ll n,a,b; cin>>n>>a>>b;

  ll ans = modpow(2, n);
  ans = (ans + mod - 1) % mod;

  ans = (ans + mod - choose(n, a, mod)) % mod;
  ans = (ans + mod - choose(n, b, mod)) % mod;

  cout << ans << endl;

  return 0;
}
