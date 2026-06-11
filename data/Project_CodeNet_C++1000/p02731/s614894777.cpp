#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double L;
  cin >> L;
  cout << fixed << setprecision(10) << L * L * L / 27 << endl;
}