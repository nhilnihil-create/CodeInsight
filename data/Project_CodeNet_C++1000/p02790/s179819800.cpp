#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b;
  string sa, sb;
  cin >> a >> b;
  rep(i, b) sa += to_string(a);
  rep(i, a) sb += to_string(b);
  cout << (sa < sb ? sa : sb) << endl;
  return 0;
}
