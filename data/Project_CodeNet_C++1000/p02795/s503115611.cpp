#include <iostream>

using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  const auto m = max(h, w);
  cout << (n + m - 1) / m << endl;
}