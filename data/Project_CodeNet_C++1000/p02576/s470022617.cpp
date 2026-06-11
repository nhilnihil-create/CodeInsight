#include <iostream>
using namespace std;

int main() {
  int a, b, c, x;
  cin >> a >> b >> c;
  if (a % b == 0) x = a / b;
  else {
    x = a / b;
    x += 1;
  }
  cout << int(x * c) << endl;
  
}