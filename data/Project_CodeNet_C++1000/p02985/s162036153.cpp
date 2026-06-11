#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> G;
vector<int> C;

void dfs(int cur, int prev, int num) {
  C.at(cur) = num;
  num = max(num, K-1);
  for (int nx : G.at(cur)) {
    if (nx == prev) continue;
    num--;
    dfs(nx, cur, max(0, num));
  }
}

int main() {
  const int MOD = 1000000007;
  cin >> N >> K;
  G.resize(N);
  for (int i = 0; i < N-1; i++) {
    int a, b; cin >> a >> b; a--; b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  C.resize(N);
  dfs(0, -1, K);
  long long ans = 1;
  for (int i = 0; i < N; i++) {
    ans = ans * C.at(i) % MOD;
  }
  cout << ans << endl;
}