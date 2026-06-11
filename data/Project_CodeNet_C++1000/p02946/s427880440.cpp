#include <iostream>

using namespace std;

int main() {
  int K, X, l, r; cin >> K >> X;
  l = X - K + 1; r = X + K - 1;
  if(l < -1000000) l = -1000000;
  if(r > 1000000) r = 1000000;
  for(int i = l; i <= r; i++) cout << i << endl;
  return 0;
}