#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  char M[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> M[i][j];
  for (int p = 0; p < (1 << n); p++) {
    for (int q = 0; q < (1 << m); q++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (M[i][j] == '#' && !((1 << i) & p) && !((1 << j) & q))
            cnt++;
        }
      }
      if (cnt == k)
        ans++;
    }
  }
  cout << ans;
  return 0;
}