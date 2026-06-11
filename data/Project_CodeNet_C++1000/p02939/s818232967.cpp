#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 1; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string s;
bool single = true;
int ans = 0;

int main() {
  cin >> s;
  ans = 1;
  rep (i, s.size()) {
    if (!single) {
      ans++;
      single = true;
      continue;
    }
    if (s[i] == s[i-1]) {
      if (i == s.size()-1) ans--;
      ans++;
      i++;
      single = false;
    }else{
      ans++;
      single = true;
    }
  }
  cout << ans << endl;
  return 0;
}
