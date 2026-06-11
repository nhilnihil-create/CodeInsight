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
  string s; cin>>s;
  ll k; cin>>k;
  ll n = s.size();

  {
    bool flg = true;
    rep(i, n-1) if (s[i] != s[i+1]) flg = false;
    if (flg) {
      cout << n*k/2 << endl;
      return 0;
    }
  }

  vector<ll> a;
  ll t = 1;
  rep(i, n-1) {
    if (s[i] == s[i+1]) t++;
    else {
      a.push_back(t);
      t = 1;
    }
  }
  a.push_back(t);

  ll ans = 0;
  for (auto v:a) {
    ans += v/2;
  }
  ans *= k;
  if (s[0] == s[n-1]) {
    ans -= (a[0]/2 + a.back()/2 - (a[0]+a.back())/2) * (k-1);
  }
  cout << ans << endl;


  return 0;
}
