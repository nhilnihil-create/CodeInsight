#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)

int N, K;
vector<int> v;

void input() {
  cin >> N >> K;
  v.resize(N);
  for (auto &e : v) { cin >> e; }
  sort(v.begin(), v.end());
}

void solve() {
  long long ans = 0;
  rep(i, 0, K) ans += v[i];
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}