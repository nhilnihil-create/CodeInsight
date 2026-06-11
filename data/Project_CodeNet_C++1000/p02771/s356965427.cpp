#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool poor = false;
  if (a == b && a != c) poor = true;
  if (b == c && b != a) poor = true;
  if (c == a && c != b) poor = true;
  if (poor) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}