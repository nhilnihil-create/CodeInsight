#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S, T, U;
  int A, B;
  cin >> S >> T >> A >> B >> U;

  if (S == U)
    A--;
  else
    B--;

  cout << A << " " << B << endl;
  return 0;
}