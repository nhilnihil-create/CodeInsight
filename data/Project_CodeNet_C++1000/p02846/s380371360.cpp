#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

  int64_t P = (A1 - B1) * T1;
  int64_t Q = (A2 - B2) * T2;
  if (P > 0) {
    P *= -1;
    Q *= -1;
  }
  if ((P + Q) < 0) {
    cout << 0 << endl;
    return 0;
  } else if ((P + Q) == 0) {
    cout << "infinity" << endl;
    return 0;
  }
  // 0 < (P + Q)
  // k x (P + Q) + P < 0 : 2 times
  // k x (P + Q) + P == 0 : 1 times
  // k x (P + Q) + P > 0 : 0 times
  int64_t S = -P / (P + Q);
  int64_t T = -P % (P + Q);
  int64_t answer = S * 2;
  if (T != 0) answer++;
  cout << answer << endl;
  return 0;
}
