#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int x, n;
  cin >> x >> n;
  int p[n];
  rep(i, n) cin >> p[i];
  int i = 0;
  while (true) {
    int A = x - i, B = x + i;
    bool a = true, b = true;
    
    rep(i, n) {
      if (A == p[i]) {
        a = false;
      }
    }
    if (a) {
      cout << A << '\n';
      return 0;
    }

    rep(i, n) {
      if (B == p[i]) {
        b = false;
      }
    }
    if (b) {
      cout << B << '\n';
      return 0;
    }
    i++;
  }
  return 0;
}