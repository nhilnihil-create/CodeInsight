#include <iostream>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << ((C > (A - B)) ? (C - (A - B)) : 0) << endl;
  return 0;
}
