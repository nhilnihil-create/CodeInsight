#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
using namespace std;


int main() {
  long long A;
  string B;
  cin >> A >> B;

  int b100 = B[0] - '0';
  int b10 = B[2] - '0';
  int b1 = B[3] - '0';

  long long b = b100 * 100 + b10 * 10 + b1;

  cout << A * b / 100 << endl;
  return 0;
}
