#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n;
const int N = 2001;
ll dp[N][N];
int a[N];
int p[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  iota(p, p + n, 0);
  sort(p, p + n, [&](int l, int r) {
    return a[l] > a[r];
  });

  for (int i = 0; i < n; ++i) {
    for (int j = 0; i + j < n; ++j) {
      int k = i + j;
      int index = p[k];
      int value = a[index];
      dp[i + 1][j] = max(dp[i + 1][j],
                         dp[i][j] + 1LL * abs(index - i) * value);
      dp[i][j + 1] = max(dp[i][j + 1],
                         dp[i][j] + 1LL * abs(n - 1 - j - index) * value);
    }
  }
  ll res = 0;
  for (int i = 0; i <= n; ++i) {
    int j = n - i;
    res = max(res, dp[i][j]);
  }
  cout << res << endl;

  return 0;
}
