#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 15;
const int M = 1010;
const int INF = 0x3f3f3f3f;

int dp[1<<N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(dp, INF, sizeof dp);
  int n, m;
  cin >> n >> m;
  dp[0] = 0;
  for (int i=1; i<=m; ++i) {
    int a, b, f = 0;
    cin >> a >> b;
    for (int j=0; j<b; ++j) {
      int x;
      cin >> x;
      f |= 1<<(x-1);
    }
    for (int j=0; j<(1<<n); ++j) {
      dp[j|f] = min(dp[j|f], dp[j]+a);
    }
  }
  cout << (dp[(1<<n)-1] == INF ? -1 : dp[(1<<n)-1]) << endl;
  return 0;
}
