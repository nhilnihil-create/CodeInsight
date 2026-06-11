#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,0,n) cin >> h[i];
  int ans = 0, cnt = 0;
  rep(i,0,n-1) {
    if (h[i] >= h[i+1]) {
      cnt++;
    } else {
      cnt = 0;
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;
  return 0;
}
