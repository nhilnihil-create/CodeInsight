#include <iostream>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  // a + b + 2sqrt(ab) < c
  // 2sqrt(ab) < c - a - b
  // 4ab < (c - a - b)^2 && c - a - b >= 0
  
  if (4 * a * b < (c - a - b) * (c - a - b) && c - a - b >= 0) {
  	cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}