#include <iostream>

using namespace std;

unsigned long long int power_aux(unsigned long long int base, unsigned long long int exponent, unsigned long long int accumulator) {
  if (exponent == 0) {
    return accumulator % 1000000007;
  } else if (base >= 1000000007 || accumulator >= 1000000007) {
    return power_aux(base % 1000000007, exponent, accumulator % 1000000007);
  } else if (exponent % 2 == 0) {
    return power_aux(base * base, exponent/2, accumulator);
  } else {
    return power_aux(base, exponent - 1, accumulator * base);
  }
}

unsigned long long int power(unsigned long long int base, unsigned long long int exponent) {
  return power_aux(base, exponent, 1);
}

int main() {
  unsigned long long int base, exponent;
  cin >> base >> exponent;
  cout << power(base, exponent) << endl;
}
  