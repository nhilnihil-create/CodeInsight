#include <iostream>
#include <cstdint>

using namespace std;

int main() {
  int64_t X, K, D, ans, hop;
  cin >> X >> K >> D;
  X = abs(X);
  
  hop = X / D;
  if (K - hop <= 0) {
    ans = X - (K * D);
    cout << ans << "\n";
    return 0;
  }

  K = K - hop;
  X = X - (D * (X / D));

  if (K % 2) {
    ans = min(abs(X - D), abs(X + D));
  }
  else {
    ans = abs(X);
  }

  cout << ans << "\n";
}