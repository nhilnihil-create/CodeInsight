#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long X, K, D;
  cin >> X >> K >> D;
  X = abs(X);
  
  if (X / D >= K) {
    cout << (X - (K * D));
  } else {
    long long cnt = X / D;
    long long step = K - cnt; // 残回数
    long long near = X % D;
    if (step % 2 == 0) {
      cout << near;
    } else {
      cout << (near - D) * -1;
    }
  }
  
}
