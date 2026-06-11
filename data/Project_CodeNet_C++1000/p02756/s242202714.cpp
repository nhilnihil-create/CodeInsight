#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  int q;
  cin >> s >> q;
  int reversed = 0;
  string sf = "", sb = "";
  rep(qi, q) {
    int t;
    cin >> t;
    if (t == 1) reversed = 1 - reversed;
    else {
      int f;
      char c;
      cin >> f >> c;
      if (reversed % 2 == f % 2) sb += c;
      else sf += c; 
    }
  }
  reverse(sf.begin(), sf.end());
  string ans = sf + s + sb;
  if (reversed) reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}