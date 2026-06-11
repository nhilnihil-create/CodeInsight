#include <bits/stdc++.h>
#define dbg() cerr <<
#define name(x) (#x) << ": " << (x) << ' ' <<

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h1, m1, h2, m2, k; cin >> h1 >> m1 >> h2 >> m2 >> k;
  int a = h1 * 60 + m1;
  int b = h2 * 60 + m2;
  cout << b - a - k << endl;
}
