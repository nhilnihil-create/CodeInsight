#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
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
  ll n; cin>>n;
  string s; cin>>s;

  vector<vector<int>> a(10);
  rep(i, n) {
    a[s[i]-'0'].push_back(i);
  }
  ll ans = 0;
  rep(i, 10) rep(j, 10) rep(k, 10) {
    if (a[i].empty() || a[j].empty() || a[k].empty()) continue;
    int ii = a[i][0];
    auto jter = upper_bound(a[j].begin(), a[j].end(), ii);
    if (jter == a[j].end()) continue;
    int jj = *jter;
    if (a[k].back() <= jj) continue;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
