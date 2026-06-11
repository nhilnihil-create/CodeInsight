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

int main()
{
  ll n,t; cin>>n>>t;
  vector<pair<ll, ll>> c(n);
  rep(i, n) {
    ll a,b; cin>>a>>b;
    c[i] = make_pair(a, b);
  }
  sort(c.begin(),c.end());

  vector<ll> dp1(t+10);
  vector<ll> dp2(t+10);
  rep(i, n) {
    ll a = c[i].first;
    ll b = c[i].second;
    for (int j=1; j<=t; j++) {
      dp2[j] = max(dp2[j], dp1[j-1] + b);
    }
    for (int j=t; j>=0; j--) {
      if (a <= j) {
        dp1[j] = max(dp1[j], dp1[j-a] + b);
      } else {
        dp1[j] = dp1[j];
      }
    }
  }
  cout << dp2[t] << endl;

  return 0;
}
