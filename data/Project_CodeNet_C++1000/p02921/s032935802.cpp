#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s >> t;
  int cnt = 0;
  rep(i,3) {
    if(s[i] == t[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
