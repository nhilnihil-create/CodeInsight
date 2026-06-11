#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((a <= b + c) ? c - (a - b) : 0) << endl;
}