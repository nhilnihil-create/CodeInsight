#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;
  if (u == s) {
    a = a-1;
  } else if (u == t) {
    b = b-1;
  }

 printf("%d %d", a, b);
  return 0;
}