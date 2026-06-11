#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int n;
  cin >> n;
  f1(i, 1, 9) f1(j, 1, 9) {
    if (i * j == n) {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}