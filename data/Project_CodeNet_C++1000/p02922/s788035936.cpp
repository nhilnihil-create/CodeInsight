#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {

  int A;
  int B;
  cin >> A >> B;
  int s = 1;
  int p = 0;
  while (s < B) {
    s = (s-1) + A;
    p++;
  }
  cout << p;

  return 0;
}
