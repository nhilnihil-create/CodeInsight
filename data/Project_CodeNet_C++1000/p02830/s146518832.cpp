#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  string ans;
  rep(i, n) {
    ans += s.substr(i, 1);
    ans += t.substr(i, 1);
  }
  cout << ans << endl;
  return 0;
}