#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<29;

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
int main(){
  int N; cin >> N;
  Graph G(N);
  for (int i = 0; i < N - 1; ++i){
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(make_pair(b, i));
    G[b].push_back(make_pair(a, i));
  }
  int max_color = 0;
  rep(i, N) max_color = max(max_color, (int)G[i].size());
  vector<int> ans(N - 1, -1);

  vector<int> dist(N, -1);
  queue<P> que;
  que.push(make_pair(0, -1));
  dist[0] = 0;
  while (!que.empty()){
    auto p = que.front(); que.pop();
    int v = p.first, c = p.second;
    int color = 1;
    if (color == c) ++color;
    for (auto e: G[v]){
      if (dist[e.first] == -1){
        dist[e.first] = dist[v] + 1;
        que.push(make_pair(e.first, color));
        ans[e.second] = color;
        ++color;
        if (color == c) ++color;
      }
    }
  }
  cout << max_color << endl;
  for (auto v: ans) cout << v << endl;
}
