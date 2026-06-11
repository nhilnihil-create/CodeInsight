#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  int N; cin >> N;
  ld x = 0;
  for (int i = 0; i < N; ++i) {
    ld a; cin >> a; x += 1.0 / a;
  }
  cout << 1.0/x << endl;
  return 0;
}
