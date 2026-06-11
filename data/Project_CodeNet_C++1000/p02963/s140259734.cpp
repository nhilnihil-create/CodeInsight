#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int S;
  cin >> S;
  long long int A, B;
  A = S / 1000000000;
  B = S % 1000000000;
  cout << 0 << " " << 0 << " ";
  cout << 1000000000 << " " << 1 << " ";
  if (S == 1000000000000000000) cout << 0 << " " << 1000000000;
  else cout << 1000000000 - B << " " << A + 1 << endl;
}