#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int N;
  cin >> N;
  double res = 0;
  for (int i = 0; i < N; ++i) {
    double a; cin >> a;
    res += 1.0 / a;
  }
  cout << fixed << setprecision(10) << 1.0/res << endl;
}