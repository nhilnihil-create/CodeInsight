#include <iostream>

using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  while(A >= B) B *= 2, --K;
  while(B >= C) C *= 2, --K;
  cout << (K >= 0 ? "Yes" : "No") << endl;
}
