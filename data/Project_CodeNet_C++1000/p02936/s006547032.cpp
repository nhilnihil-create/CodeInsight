#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
void dfs(vector<int> &ans, vector<vector<int>> &_Tree, vector<int> &score,
         ll num, int id, vector<int> &dis) {
  num += score[id];
  ans[id] = num;
  REP(i, _Tree[id].size()) {
    if (dis[id] >= dis[_Tree[id][i]]) continue;
    dfs(ans, _Tree, score, num, _Tree[id][i], dis);
  }
  return;
}
int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> _Tree(N, vector<int>(0));
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    _Tree[b].push_back(a);
    _Tree[a].push_back(b);
  }
  vector<int> score(N, 0);
  REP(i, Q) {
    int p, x;
    cin >> p >> x, p--;
    score[p] += x;
  }
  vector<int> dis(N, -1);
  queue<P> que{};
  que.push(P(0, 0));
  while (!que.empty()) {
    P tmp = que.front();
    que.pop();
    dis[tmp.first] = tmp.second;
    REP(i, _Tree[tmp.first].size()) {
      if (dis[_Tree[tmp.first][i]] != -1) continue;
      que.push(P(_Tree[tmp.first][i], tmp.second + 1));
    }
  }
  vector<int> ans(N, 0);
  dfs(ans, _Tree, score, 0, 0, dis);

  REP(i, N) cout << ans[i] << " ";
  cout << endl;
}