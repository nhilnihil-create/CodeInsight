#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  string s, t;
  cin >> s >> t;
  int ans = 0;
  rep(i,s.length()) {
    if (s[i] != t[i]) ++ans;
  }
  cout << ans << endl;
}