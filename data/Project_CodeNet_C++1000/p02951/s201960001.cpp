#include <iostream>
using namespace std;

int main() {

  int A, B, C;
  cin >> A >> B >> C;

  int rest = A-B;

  cout << max(C-rest, 0) << endl;
  return 0;
}