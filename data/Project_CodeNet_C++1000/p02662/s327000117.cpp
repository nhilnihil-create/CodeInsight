#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 3000 + 7;
int n, s, dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j <= s; j++) {
      dp[i][j] = mul(2, dp[i - 1][j]);
      if (j >= x) {
        dp[i][j] = add(dp[i][j], dp[i - 1][j - x]);
      }
    }
  }
  cout << dp[n][s] << "\n";
  return 0;
}
