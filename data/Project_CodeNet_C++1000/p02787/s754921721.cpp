#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  int W,N;
  cin >> W >> N;
  vector<ll> dp(W+1,100000000000);
  for (int i = 0; i < W+1; i++) {
  }
  dp[0] = 0;
  int w,v;
  for (int i = 0; i < N; i++) {
    cin >> w >> v;
    for (int j = 0; j < W+1; j++) {
      dp[j] = min(dp[j], dp[max(0,j-w)]+v);
    }
  }
  cout << dp[W] << endl;
  return 0;
}