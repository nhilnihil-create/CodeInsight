#include <bits/stdc++.h>

using namespace std;

const int N = 310;

long long dp[N][N], tmp[N][N];
long long h[N];
int n, K;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);

  set<long long> s;
  vector<long long> v;
  map<long long, int> pos;

  cin >> n >> K;
  s.insert(0);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    s.insert(h[i]);
  }

  for (int val : s) {
    v.push_back(val);
    pos[val] = v.size() - 1;
  }

  for (int i = 0; i < n; ++i) {
    for (int k = 0; k <= K; ++k) {
      if (i == 0) {
        for (int j = 0; j < v.size(); ++j) {
          if (k == 0) {
            dp[k][j] = (v[j] == h[i] ? h[i] : (1LL << 60));
          } else {
            dp[k][j] = v[j];
          }
        }
      } else {
        long long val = (1LL << 60);
        long long val2 = (1LL << 60);
        for (int j = 0; j < v.size(); ++j) {
          if (k > 0) {
            val = min(val, tmp[k-1][j] - v[j]);
          }
          dp[k][j] = v[j] + val;
        }
        if (i > 0 && k > 0) {
          val = 1LL << 60;
          for (int j = v.size()-1; j >= 0; --j) {
            val = min(val, tmp[k-1][j]);
            dp[k][j] = min(dp[k][j], val);
          }
        }
        const int p = pos[h[i]];
        for (int j = 0; j < v.size(); ++j) {
          dp[k][p] = min(dp[k][p], tmp[k][j] + max(0LL, h[i] - v[j]));
        }
      }
    }

    swap(dp, tmp);
  }

  long long ans = 1LL << 60;
  for (int k = 0; k <= K; ++k) {
    for (int j = 0; j < v.size(); ++j) {
      ans = min(ans, tmp[k][j]);
    }
  }

  cout << ans << endl;

  return 0;
}
