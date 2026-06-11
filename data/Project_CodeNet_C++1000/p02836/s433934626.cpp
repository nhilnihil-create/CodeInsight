#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  string rs = s;
  reverse(rs.begin(), rs.end());
  int ans = 0;
  for(int i=0; i * 2 < s.size(); i++) {
    if(s[i] != rs[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}