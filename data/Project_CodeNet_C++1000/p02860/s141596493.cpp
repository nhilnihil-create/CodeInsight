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
  if (n % 2 != 0) {
    cout << "No" << '\n';
    return 0;
  }
  string st, ts;
  rep(i, n / 2) {
    st += s[i];
    ts += s[n / 2 + i];
  }
  cout << (st == ts ? "Yes" : "No") << '\n';
  return 0;
}