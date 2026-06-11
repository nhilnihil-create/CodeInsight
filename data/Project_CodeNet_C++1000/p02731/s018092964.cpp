#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  double l;
  cin >> l;
  l /= 3;
  cout << fixed << setprecision(15);
  cout << l * l * l << endl;
  return 0;
}