#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double pi = 3.14159265359;
  double r;
  cin >> r;
  cout << fixed << setprecision(6);
  cout << (r * r * pi) << ' ';
  cout << (2 * r * pi) << endl;
  return 0;
}