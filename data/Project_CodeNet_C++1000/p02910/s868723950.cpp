#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  rep(i, s.size()) {
    if(i % 2 == 0 && s[i] == 'L') {
      ok = false;
      break;
    }
    if(i % 2 != 0 && s[i] == 'R') {
      ok= false;
      break;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}