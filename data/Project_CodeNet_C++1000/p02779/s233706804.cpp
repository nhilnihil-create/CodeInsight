#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int n, x;
  cin >> n;
  vector<int> a(n);
  set<int> b;
  rep(i, n) {
    cin >> x;
    b.insert(x);
    a[i] = x;
  }
  cout << (a.size() == b.size() ? "YES" : "NO") << '\n';
  return 0;
}