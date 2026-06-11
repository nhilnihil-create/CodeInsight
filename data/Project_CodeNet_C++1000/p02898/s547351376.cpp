#include <iostream>
using namespace std;

int main() {
  int n, c = 0;
  short int k, h;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> h;
    if (h >= k) ++c;
  }
  cout << c << '\n';
  return 0;
}