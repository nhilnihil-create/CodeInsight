#include <iostream>
#include <cstdio>
using namespace std;
   
int main() {
  int a, b, d, r;
  double f;
  cin >> a >> b;
  cout << a / b << " " << a % b << " ";
  printf("%.5f\n", 1.0 * a / b);
  return 0;
}