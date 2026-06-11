#include <iostream>
using namespace std;
int main() {
  int A,B,C;
  cin >> A >> B >> C;
  bool isPoor = false;
  if (A == B && A != C) isPoor = true;
  if (A == C && A != B) isPoor = true;
  if (B == C && A != B) isPoor = true;
  if (isPoor) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}