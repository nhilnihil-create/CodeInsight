#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int K, A, B;
  cin >> K >> A >> B;
  bool ok = false;
  for (int i = A; i <= B; i++) {
    if (i % K == 0) {
      ok = true;
      break;
    }
  }

  if (ok) {
    cout << "OK" << endl;
  } else {
    cout << "NG" << endl;
  }

  return 0;
}