#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)

int N, M, K;
vector<int> a, b;
void input() {
  cin >> N >> M >> K;
  a.resize(N);
  for (auto &e : a) cin >> e;
  b.resize(M);
  for (auto &e : b) cin >> e;
}

void solve() {
  ll t = 0;
  for (auto &e : b) t += e;

  int ans = 0;
  int j = M;
  rep(i, 0, N + 1) {
    while (j > 0 && t > K) {
      --j;
      t -= b[j];
    }
    if (t > K) break;
    ans = max(ans, (i + j));  //(a=0冊,b=j冊)～(a=N冊,b=0冊)
    if (i == N) break;
    t += a[i];
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}