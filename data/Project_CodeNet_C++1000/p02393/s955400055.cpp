#include <iostream>
using namespace std;

void replace(int *x, int *y) {
  if (*x > *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
  }
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  replace(&a, &b);
  replace(&a, &c);
  replace(&b, &c);
  cout << a << ' ' << b << ' ' << c << endl;
}