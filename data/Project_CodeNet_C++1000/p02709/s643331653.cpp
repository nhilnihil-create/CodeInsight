#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 2e3 + 5;

ll dp[N][N];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < pair < int, int > > a (n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;

  sort (a.begin() + 1, a.end(), greater < pair < int, int > > ());

  for (int l = n; l >= 1; l--) {
    for (int r = l; r <= n; r++) {
      int idx = l + n - r;
      int i = a[idx].second;
      if (idx < 1 || idx > n) continue;
      if (l == r) {
        dp[l][r] = (ll)a[n].first * abs (r - i);
        continue;
      }
      dp[l][r] = max (dp[l + 1][r] + (ll)a[idx].first * abs(i - l), dp[l][r - 1] + (ll)a[idx].first * abs(r - i));
    }
  }

  cout << dp[1][n] << '\n';
}
