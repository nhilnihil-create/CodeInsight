#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  ll A, B, K;
  cin >> A >> B >> K;

  if (K <= A)
    cout << A - K << " " << B << endl;
  else if (K <= A + B)
    cout << 0 << " " << B - (K - A) << endl;
  else
    cout << 0 << " " << 0 << endl;
  return 0;
}