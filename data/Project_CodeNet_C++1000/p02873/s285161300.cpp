#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  ll ans = 0, last = 0;
  rep(i,0,S.size()-1) {
    ll cnt = 0;
    if (S[i] == '<') {
      while(S[i] == S[i+cnt]) {
        cnt++;
        ans += cnt;
      }
      i += cnt - 1;
      last = cnt;
    } else {
      while(S[i] == S[i+cnt]) {
        cnt++;
        ans += cnt;
      }
      ans -= min(cnt, last);
      i += cnt - 1;
      last = cnt;
    }
  }

  cout << ans << endl;
  return 0;
}
