#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const long long LINF = 1000000000000000018ll;
const int INF = 1000000009;
const int mod = 1000000007;
const int mod2 = 998244353;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int K;
map<pair<int, int>, int> mp;

void dfs(int cur_v, int par_v, int prev_color, vector<vector<int>> &T) {
  int nxt_color = 1;
  for (int i = 0; i < (int)T[cur_v].size(); i++) {
    int nxt_v = T[cur_v][i];
    if (nxt_v == par_v) {
      continue;
    }
    if (nxt_color == prev_color) {
      nxt_color++;
    }
    mp[make_pair(cur_v, nxt_v)] = nxt_color;
    mp[make_pair(nxt_v, cur_v)] = nxt_color;
    dfs(nxt_v, cur_v, nxt_color, T);
    nxt_color++;
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout << std::setprecision(20) << std::fixed;

  int N;
  cin >> N;
  vector<vector<int>> Tree(N);
  vector<pair<int, int>> Edges(N - 1);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
    Edges[i] = make_pair(a, b);
  }

  int color_num = 0;
  for (int i = 0; i < N; i++) {
    color_num = max(color_num, (int)Tree[i].size());
  }

  K = color_num;
  cout << K << endl;

  dfs(0, -1, 0, Tree);
  for (int i = 0; i < N - 1; i++) {
    cout << mp[Edges[i]] << "\n";
  }

  return 0;
}