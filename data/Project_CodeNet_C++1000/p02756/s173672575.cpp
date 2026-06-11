#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
//#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  string S; cin >> S;
  int Q; cin >> Q;
  
  bool k = true;
  string B, E;
  rep(i, Q) {
    int T; cin >> T;
    if(T == 1) {
      k = !k;
    }
    if(T == 2) {
      int F; cin >> F;
      char C; cin >> C;
      if(F == 1) {
        if(k) B += C;
        else E += C;
      } else {
        if(k) E += C;
        else B += C;
      }
    }
  }
  
  reverse(all(B));
  string ans = B+S+E;
  if(k) cout << ans << endl;
  else {
    reverse(all(ans));
    cout << ans << endl;
  }
  

}