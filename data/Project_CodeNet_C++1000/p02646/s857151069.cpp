#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  long long int a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;

  if (v > w) {
    if (abs(b - a) <= (v - w) * t) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}