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

struct Doubling {
  const ll LOG = 60;
  vector<vector<ll>> table;

  Doubling(ll n) {
    table.assign(LOG, vector<ll>(n, -1));
  }
  void set_next(ll k, ll x) {
    table[0][k] = x;
  }
  void build() {
    for (int k=0; k<LOG-1; k++) {
      for (int i=0; i<(int)table[k].size(); i++) {
        if (table[k][i] == -1) table[k+1][i] = -1;
        else table[k+1][i] = table[k][table[k][i]];
      }
    }
  }
  ll query(ll k, ll t) {
    for (int i=LOG-1; i>=0; i--) {
      if ((t>>i)&1) k = table[i][k];
    }
    return k;
  }
};

int main()
{
  ll n,k; cin>>n>>k;

  Doubling db(n);
  rep(i, n) {
    ll a; cin>>a; a--;
    db.set_next(i, a);
  }

  db.build();
  cout << db.query(0, k)+1 << endl;

  return 0;
}
