#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
#define N 2701

ll C[N][N];

void init() {
  C[0][0] = C[1][0] = C[1][1] = 1;
  for (int i = 2; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) C[i][j] = 1;
      else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
  }
}

int main() {
  int S;
  cin >> S;
  if (S < 3) {
    cout << 0 << '\n';
    return 0;
  }
  init();
  ll ans = 0;
  for (int i = 1; i * 3 <= S; ++i) {
    ans = (ans + C[i+S-i*3-1][i-1]) % mod;
  }
  cout << ans << '\n';
  return 0;
}
