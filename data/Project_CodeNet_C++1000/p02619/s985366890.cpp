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
  ll d; cin>>d;
  vector<ll> c(26);
  rep(i, 26) cin>>c[i];
  vector<vector<ll>> s(d, vector<ll>(26));
  rep(i, d) rep(j, 26) cin>>s[i][j];
  vector<ll> t(d);
  rep(i, d) {
    cin>>t[i]; t[i]--;
  }

  vector<ll> nsc(26);
  vector<ll> score(d);
  vector<ll> last(26, -1);
  rep(i, d) {
    last[t[i]] = i;
    rep(j, 26) {
      if (t[i] == j) nsc[j] += s[i][j];
      else nsc[j] -= c[j]*(i-last[j]);
    }
    ll sum = 0;
    rep(j, 26) sum += nsc[j];
    score[i] = sum;
  }

  rep(i, d) cout << score[i] << endl;

  return 0;
}
