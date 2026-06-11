#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[3003];

int main() {
  // greedy、逆順、O(NT)は通る
  int N, T;
  cin >> N >> T;
  vector<P> AB(N);
  rep(i, N) {
    cin >> AB[i].first >> AB[i].second;
  }
  sort(AB.begin(), AB.end(), [](P x, P y) {
    return x.first < y.first;
  });
  rep(i, N) {
    int A, B;
    A = AB[i].first;
    B = AB[i].second;    
    for (int j = T-1; j >= 0; j--) {
      int nj = j + A;
      if (nj > T) nj = T;
      dp[nj] = max(dp[nj], dp[j] + B);
    }
  }
  int ans = 0;
  rep(i, T+1) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}