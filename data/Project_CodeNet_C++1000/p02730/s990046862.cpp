#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  string S, T, x, y, xx, yy;
  cin >> S;
  int N;
  N = S.size();

  T = S;
  reverse(T.begin(), T.end());

  if (S != T) {
    cout << "No" << endl;
    return 0;
  }

  x = S.substr(0, (N - 1) / 2);
  y = S.substr((N + 3) / 2 - 1);

  xx = x;
  yy = y;

  reverse(xx.begin(), xx.end());
  reverse(yy.begin(), yy.end());

  if (x != xx || y != yy) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}