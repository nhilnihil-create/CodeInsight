#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
  int N, X, T;
  cin >> N >> X >> T;
  printf("%d", (int)ceil((float)N / (float)X) * T);
  return 0;
}