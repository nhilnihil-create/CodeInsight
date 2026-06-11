#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
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
  ll n,m; cin>>n>>m;
  vector<vector<ll>> t(100010);
  rep(i, n) {
    ll a,b; cin>>a>>b;
    t[a].push_back(b);
  }
  ll ans = 0;
  priority_queue<ll> q;
  for (int i=1; i<=m; i++) {
    for (auto v:t[i]) q.push(v);
    if (!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;

  return 0;
}
