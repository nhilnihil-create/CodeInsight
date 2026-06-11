#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int v, e;
vector<int> G[10000];
int in[10000];
vector<int> ans;

int main() {
  cin >> v >> e;
  REP(i, e) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);  // s -> t
    in[t]++;
  }
  queue<int> que;
  REP(i, v) {
    if (in[i] == 0) que.push(i);
  }
  while (que.size()) {
    int p = que.front();
    que.pop();
    ans.push_back(p);
    REP(i, G[p].size()) {
      int q = G[p][i];
      in[q]--;
      if (in[q] == 0) que.push(q);
    }
  }
  REP(i, ans.size()) cout << ans[i] << endl;
  return 0;
}
