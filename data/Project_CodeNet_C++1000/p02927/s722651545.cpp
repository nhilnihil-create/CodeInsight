#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int M, D;
  cin >> M >> D;

  int ans = 0;
  int d1, d2;
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= D; j++) {
      if (j <= 10) continue;
      
      d1 = j / 10;
      d2 = j % 10;
      if (d1>=2 && d2>=2 && i==d1*d2) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}