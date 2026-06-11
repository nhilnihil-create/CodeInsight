#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = -1;
  for (int i = 1; i <= 20000; ++i) {
    if ((int)(0.08 * i) == a && (int)(0.1 * i) == b) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}