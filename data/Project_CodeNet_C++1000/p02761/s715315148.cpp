#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, M; cin >> N >> M;
  string ans;
  rep(i, N) ans += 'a';
  
  rep(i, M) {
    int s; cin >> s;
    char c; cin >> c;
    if(ans[s-1] == 'a' || ans[s-1] == c) {
      ans[s-1] = c;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  rep(i, N) if(ans[i] == 'a') {
    if(i == 0 && N > 1) ans[i] = '1';
    else ans[i] = '0';
  }
  
  if(ans[0] == '0' && N > 1) {
    cout << -1 << endl;
    return 0;
  } else {
    cout << ans << endl;
    return 0;
  }

}