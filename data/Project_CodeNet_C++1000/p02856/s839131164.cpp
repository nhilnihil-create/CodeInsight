#include <bits/stdc++.h>
using namespace std;

int m;
long long d, c, D = 0, T = 0;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> d >> c;
    D += c;
    T += (d * c);
  }
  cout << (D - 1 + ((T - 1) / 9)) << endl;
}