#include <bits/stdc++.h>
using namespace std;

int n;
long a[2000];
long dp[2001][2001];

int main() {
  using PP = pair<long, long>;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<PP> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(PP(a[i], i));
  }
  sort(v.begin(), v.end(), greater<PP>());
  
  for (int k = 0; k < n; ++k) {
    int pos = v[k].second;
    long val = a[pos];
    for (int i = 0; i <= k; ++i) {
      int j = k - i;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + val * abs(pos - i));
      dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + val * abs(pos - (n - 1 - j)));
    }
  }
  
  long mx = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      mx = max(mx, dp[i][j]);
    }
  }
  
  cout << mx << endl;
}