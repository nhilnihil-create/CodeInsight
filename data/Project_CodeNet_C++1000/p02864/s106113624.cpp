#include <bits/stdc++.h>
using namespace std;

const long inf = 1e18;
int n, r;
long a[300];
long b[300];
long dp[300][300][300];
long dq[300][300][300];
long dr[300][300][300];

void modify(int i) {
  for (int j = 0; j < n; ++j) {
    long q = inf;
    for (int k = n - 1; k >= 0; --k) {
      q = min(q, dp[i][j][k]);
      dq[i][j][k] = q;
    }

    long r = inf;
    for (int k = 0; k < n; ++k) {
      dr[i][j][k] = r;
      r = min(r, dp[i][j][k] - b[k]);
    }
  }
}

int main() {
  cin >> n >> r;
  if (n == r) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) b[i] = a[i];
  sort(b, b + n);
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= r; ++j) {
      for (int k = 0; k < n; ++k) {
        dp[i][j][k] = inf;
        if (i == 0 && j == (b[k] != a[0])) {
          dp[i][j][k] = b[k];
        }
      }
    }
  }
  
  modify(0);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= r; ++j) {
      for (int k = 0; k < n; ++k) {
        int pj = b[k] == a[i] ? j : j - 1;
        if (pj < 0) continue;
        dp[i][j][k] =
          min(dp[i][j][k], 
            min(dq[i - 1][pj][k], b[k] + dr[i - 1][pj][k])); 
      }
    }
    modify(i);
  }

  long mn = inf;
  for (int j = 0; j <= r; ++j) {
    for (int k = 0; k < n; ++k) {
      mn = min(mn, dp[n - 1][j][k]);
    }
  }
  cout << mn << endl;
}