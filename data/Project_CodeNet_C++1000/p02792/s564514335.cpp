#include <bits/stdc++.h>
 
using namespace std;

int f[10][10];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int foo = i;
    int fi;
    int la = foo % 10;
    while (foo > 0) {
      if (foo < 10) fi = foo;
      foo /= 10;
    }
    f[fi][la]++;
  }
  long long ans = 0;
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      ans += f[i][j] * f[j][i];
    }
  }
  cout << ans << '\n';
  return 0;
}