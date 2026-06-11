#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  swap(A, B);
  swap(A, C);
  cout << A << " " << B << " " << C << endl;
}