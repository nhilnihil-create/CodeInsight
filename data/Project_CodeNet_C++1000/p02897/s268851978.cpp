#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << 0.5000000000 << endl;
    return 0;
  }
  int k = n/2 + 1;
  double ans = (double)k / (double)n;
  printf("%.10lf\n", ans);
  return 0;
}