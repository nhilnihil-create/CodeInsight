#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  int l = 1, r = 99;
  bool ok = true;
  rrep(i,1000) {
    if (l <= n && n <= r) ok = false;
    l += 105;
    r += 100;
  }
  if (ok) cout << 1 << endl;
  else cout << 0 << endl;
}
