#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long a;
  double b;
  cin >> a >> b;
  int _b = int(round(b * 100));
  cout << a * _b / 100 << endl;
}
