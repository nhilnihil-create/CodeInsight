#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  long long X, K, D;
  cin >> X >> K >> D;
  long long ans;
  if (X < 0) {
    X = -1 * X;
  }
  long count = X / D;  // 残り距離が正としたときの試行回数
  if (count > K) {
    ans = X - K * D;
    cout << ans << endl;
    return 0;
  }
  long distance = X - D * count;  // 残り距離
  count = K - count;  // 残り試行回数
  if (count % 2 == 0) {
      ans = distance;
  } else {
      ans = D - distance;
  }
  cout << ans << endl;
  return 0;
}
