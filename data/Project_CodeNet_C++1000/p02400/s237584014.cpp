#include <iostream>
#include <iomanip>
using namespace std;

int main() {

  long double p = 3.141592653589;

  long double in;
  cin >> in;

  cout << fixed << setprecision(10) << p * in * in << " " << p * in * 2 << endl;

  return 0;

}