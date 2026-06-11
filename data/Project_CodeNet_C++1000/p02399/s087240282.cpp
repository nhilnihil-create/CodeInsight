#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  unsigned long a, b;
  cin >> a >> b;
  cout << (a / b) << ' ';
  cout << (a % b) << ' ';
  cout << fixed << setprecision(6) << ((double)a / b) << endl;
  return 0;
}