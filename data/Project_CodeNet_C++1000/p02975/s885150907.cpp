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
  vector<ll> a(n);
  rep(i, n) cin>>a[i];

  bool allzero = true;
  rep(i, n) if (a[i] != 0) allzero = false;
  if (allzero) {
    cout << "Yes" << endl;
    return 0;
  }

  if (n%3 != 0) {
    cout << "No" << endl;
    return 0;
  }

  map<ll, ll> mp;
  rep(i, n) mp[a[i]]++;
  if (mp.find(0) != mp.end()) {
    if ((int)(mp.size()) > 2) {
      cout << "No" << endl;
      return 0;
    }
    bool flg = true;
    for (auto v:mp) {
      if (v.first == 0 && v.second != n/3) flg = false;
      if (v.first != 0 && v.second != 2*n/3) flg = false;
    }
    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }

  if ((int)(mp.size()) != 3) {
    cout << "No" << endl;
    return 0;
  }
  vector<ll> d;
  for (auto v:mp) {
    d.push_back(v.first);
    if (v.second != n/3) {
      cout << "No" << endl;
      return 0;
    }
  }
  if ((d[0]^(d[1]^d[2])) == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
