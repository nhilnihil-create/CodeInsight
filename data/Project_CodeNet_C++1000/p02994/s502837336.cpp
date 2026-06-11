#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> Aji(n+1);
  int tot = 0;
  bool flg = 0;
  int plus = 1001;
  int minus = -1001;
  for (int i = 1;i <= n; i++) {
    Aji[i] = l+i-1;
    tot += Aji[i];
    if (Aji[i] == 0) flg = 1;
    else if (flg != 1 && Aji[i] > 0) plus = min(Aji[i], plus);
    else if (flg != 1 && Aji[i] < 0) minus = max(Aji[i], minus);
  }

  int ans;
  if (flg) ans = tot;
  else if (plus == 1001) {
    ans = tot-minus;
  } else if (minus == -1001) {
    ans = tot-plus;
  } else {
    ans = min(tot-plus, tot - minus);
  }

  cout << ans << endl;
  return 0;
}