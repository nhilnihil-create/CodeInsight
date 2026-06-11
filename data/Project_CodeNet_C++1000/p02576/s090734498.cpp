#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int main() {
  int N, X, T;
  cin >> N >> X >> T;

  cout << fixed <<  (int) ceil((float) N / X) * T << endl;

  return 0;
}
