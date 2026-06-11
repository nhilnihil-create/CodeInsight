#include <iostream>
using namespace std;

int main() {
  long long R, C;
  cin >> R >> C;
  long long R1 = 0, R2;
  long long ans = 0;
  for (int i = 0; i < C; i += 2) R1++;
  if (C % 2 == 0) R2 = R1;
  else R2 = R1 - 1;
  ans += (R1 + R2) * (R / 2);
  ans += R1 * (R % 2);
  if (C == 1 || R == 1) {
    cout << 1 << endl;
  } else {
  cout << ans << endl;
  }

  return 0;
}