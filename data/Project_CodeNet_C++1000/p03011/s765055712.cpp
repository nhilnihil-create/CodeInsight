#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, D, E;
  cin >> A >> B >> C;
  D = A + B + C;
  E = max(max(A, B), C);
  cout << D - E << endl;
}
