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
const ll mod = 1000000007;

int main()
{
  int n,k; cin>>n>>k;
  string s; cin>>s;

  int cnt = 0;
  for (int i=1; i<n; i++) {
    if (s[i-1] != s[i]) cnt++;
  }
  int t = max(0, cnt-k*2);
  cout << n-t-1 << endl;

  return 0;
}
