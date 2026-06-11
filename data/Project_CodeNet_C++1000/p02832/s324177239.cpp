#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int now = 1;
  int ans = 0;
  rep(i,n) {
    if (now == a[i]) {
      now++;
      continue;
    }
    else ans++;
  }
  if (now == 1) ans = -1;
  cout << ans << endl;
  return 0;
}