#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n,c,k;
  string s;
  cin >> n >> k >> c >> s;

  vector<int> l(k+1,-1), r(k+1,-1);
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if(s[i] == 'o') {
      l[cnt] = i;
      i+=c;
      cnt++;
    }
    if(cnt > k) break;
  }
  cnt = k;
  for (int i = n - 1; i >= 0; i--) {
    if(s[i] == 'o') {
      r[cnt] = i;
      i-=c;
      cnt--;
    }
    if(cnt < 0) break;
  }

  for (int i = 1; i <= k; i++) {
    if(l[i] == r[i]) cout << l[i] + 1 << '\n';
  }


}