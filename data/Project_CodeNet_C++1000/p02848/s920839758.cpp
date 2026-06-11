#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int n;
  string s;
  cin >> n >> s;
  rep(i, s.size()) {
    if (s[i] + n > 'Z') {
      s[i] = 'A' + (n - 1 - ('Z' - s[i]));
    } else {
      s[i] += n;
    }
  }
  cout << s << '\n';
  return 0;
}