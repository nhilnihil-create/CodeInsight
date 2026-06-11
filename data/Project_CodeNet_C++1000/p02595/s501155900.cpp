#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
  int N, D, res = 0;
  long long x, y;
  cin >> N >> D;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    res += (sqrt(x*x + y*y) <= D);
  }
  cout << res << '\n';
  return 0;
}