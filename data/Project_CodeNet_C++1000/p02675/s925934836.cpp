#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  n %= 10;
  if (n == 3) puts("bon");
  else if (n == 0 || n == 1 || n == 6 || n == 8) puts("pon");
  else puts("hon");
}
