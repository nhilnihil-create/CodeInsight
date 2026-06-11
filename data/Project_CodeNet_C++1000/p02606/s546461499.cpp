#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int l, r, d;
  cin >> l >> r >> d;

  int ans = 0;
  for (int i = l; i <= r; i++) {
    if (i%d == 0) ans++;
  } 
  cout << ans << endl;
  
  return 0;
}