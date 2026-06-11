#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  string s, t;
  cin >> s >> t;
  int ans = 0;
  rep(i, 3) {
    if(s[i] == t[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}