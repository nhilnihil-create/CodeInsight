#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int P, Q, R;
  cin >> P >> Q >> R;
  int ans = min(P + Q, min(Q + R, R + P));
  cout << ans << endl;
  return 0;
}