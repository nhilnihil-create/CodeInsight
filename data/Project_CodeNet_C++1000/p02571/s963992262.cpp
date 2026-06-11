#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  string s, t;
  cin >> s >> t;
  int qs = s.size();
  int qt = t.size();
  int ans = 0;
  rep(i, qs-qt+1){
    int match = 0;
    rep(j, qt){
      if(s[i+j] == t[j]) match++;
    }
    ans = max(ans, match);
  }
  cout << qt - ans << endl;
  return 0;
}