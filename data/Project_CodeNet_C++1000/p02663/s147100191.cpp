/**
 *    author: Behradm
 *    Created: 02.06.2020 12:23:34
 *    In the Name of God
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int dh = h2 - h1;
  int dm = m2 - m1;
  int res = dh * 60 + dm;
  cout << res - k << '\n';
  return 0;
}


