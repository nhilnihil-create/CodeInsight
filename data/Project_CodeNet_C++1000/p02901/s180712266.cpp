#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;

int main() {
  int N, M;
  cin >> N >> M;
  vector<P> keys(M);
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    int bitSum = 0;
    rep(j, B) {
      int C;
      cin >> C;
      --C;
      bitSum += 1<<C;
    }
    //keys[i].first = A;
    //keys[i].second = bitSum;
    keys[i] = make_pair(A, bitSum);
  }
  vector<int> dp(1<<N, INF); // dp.back()がans
  dp[0] = 0;
  for (int i = 0; i < 1<<N; i++) {
    for (auto p : keys) {
      int newPrice = dp[i] + p.first;
      int newBit = i | p.second;
      dp[newBit] = min(dp[newBit], newPrice);
    }
  }
  int ans = dp.back();
  if (ans == INF) ans = -1;
  cout << ans << '\n';
  return 0;
}
