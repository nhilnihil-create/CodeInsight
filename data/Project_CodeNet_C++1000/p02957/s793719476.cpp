#include <iostream>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if ((A + B) & 1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ((A + B) >> 1) << endl;
  }
  return 0;
}
