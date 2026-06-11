#include <bits/stdc++.h>
using namespace std;
const int mx = 300000;
bool sieve[mx];
int ps[mx];
int main() {
  fill(sieve + 2, sieve + mx, 1);
  for (int i = 2; i < mx; i++) if (sieve[i]) for (int j = 2 * i; j < mx; j += i) sieve[j] = false;
  for (int i = 1; i < mx; i++) ps[i] = ps[i - 1] + sieve[i];
  while (true) {
    int n; cin >> n; if (n == 0) return 0;
    cout << ps[2 * n] - ps[n] << endl;
  }
}
