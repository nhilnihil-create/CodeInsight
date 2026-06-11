#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int k;
  string s;
  cin >> k >> s;
  string ans;
  char add;
  rep(i,k) {
    try {
      add = s.at(i);
    } catch(out_of_range) {
      break;
    }
    ans += add;
  }
  if (s.size() > k) ans += "...";
  cout << ans << endl;
  return 0;
}