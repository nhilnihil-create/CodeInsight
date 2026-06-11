#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  priority_queue<int> que;
  rep(i, N) {
    cin >> H[i];
    que.push(H[i]);
  }
  for (int i = 0; i < K; i++) {
    if (que.empty()) break;
    que.pop();
  }
  ll ans = 0;
  while (!que.empty()) {
    ans += que.top(); que.pop();
  }
  cout << ans << '\n';
  return 0;
}