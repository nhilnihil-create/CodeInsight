#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int m1,d1,m2,d2;
  cin >> m1 >> d1;
  cin >> m2 >> d2;
  if (d2 - d1 <= 0) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}