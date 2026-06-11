#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  rep(i, N) cin >> L[i];

  int ans = 1, total = 0;
  for (int D: L) {
    total += D;
    if (total <= X) ans++;
    else break;
  }
  cout << ans << endl;
  return 0;
}