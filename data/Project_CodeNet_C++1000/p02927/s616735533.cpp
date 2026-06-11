#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j/10 >= 2) {
        if (j%10 >= 2) {
          if (i == (j/10)*(j%10)) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}