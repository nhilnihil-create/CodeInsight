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
  string s, t;
  cin>>s>>t;
  int sl = s.size();
  int tl = t.size();

  vector<vector<int>> dic(26);
  rep(i, sl) {
    int x = s[i]-'a';
    dic[x].push_back(i+1);
  }

  ll ans = 0;
  ll now = 0;
  rep(i, tl) {
    int x = t[i]-'a';
    if (dic[x].empty()) {
      cout << -1 << endl;
      return 0;
    }
    auto itr = upper_bound(dic[x].begin(), dic[x].end(), now);
    if (itr == dic[x].end()) {
      ans += sl;
      now = 0;
      itr = upper_bound(dic[x].begin(), dic[x].end(), now);
    }
    now = *itr;
  }
  cout << ans+now << endl;

  return 0;
}
