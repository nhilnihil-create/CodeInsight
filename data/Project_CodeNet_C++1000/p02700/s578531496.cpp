#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int tk = (c + b - 1) / b;
  int ao = (a + d - 1) / d;
  if (tk <= ao) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}