#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> a(n); for(int i = 0; i < n; i++) cin >> a[i];
  long long dp[n] = {0LL};
  dp[0] = 1000;

  for(int i = 1; i < n; i++) {
    dp[i] = dp[i-1];
    for(int j = 0; j < i; j++) {
      long long v = dp[j] / a[j];
      long long w = dp[j] + (a[i] - a[j]) * v;
      dp[i] = max(dp[i], w);
    }
  }
  cout << dp[n-1] << endl;
  return 0;
}
