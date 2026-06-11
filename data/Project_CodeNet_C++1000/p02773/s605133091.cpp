#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  int n;
  cin >> n;
  map<string, int> s;
  rep(i, n) {
    string t;
    cin >> t;
    s[t] += 1;
  }
  int maxmum = 0;
  for (auto x : s) {
    int y = x.second;
    maxmum = max(y, maxmum);
  }
  for (auto x : s) {
    if (s[x.first] == maxmum) cout << x.first << '\n';
  }
  return 0;
}