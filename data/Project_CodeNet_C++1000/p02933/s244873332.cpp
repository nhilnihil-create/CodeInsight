#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a;
  cin >> a;
  string s;
  cin >> s;
  if (a >= 3200) cout << s << '\n';
  else puts("red");
  return 0;
}