#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  long double a, b, c;
  cin >> a >> b >> c;

  if (a + 2 * sqrt(a * b) + b < c)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;

}