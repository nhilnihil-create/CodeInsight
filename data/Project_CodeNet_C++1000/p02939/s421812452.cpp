#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  string S; cin >> S;
  
  string s = "";
  int ans = 0;
  int now = 0;
  
  rep(i, S.size()) {
    string ss = S.substr(now, i-now+1);
    if(s != ss) {
      s = ss;
      ans++;
      now = i+1;
    }
  }
  cout << ans << endl;
  
}