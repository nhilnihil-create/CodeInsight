#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if ((A != B && B != C) && C != A) {
    cout << "No" << endl;
  } else if ((A == B && B == C) && C == A) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}