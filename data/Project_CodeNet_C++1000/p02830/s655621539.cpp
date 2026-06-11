#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  string s, t, ans;
  cin >> s >> t;
  rep(i,n) {
    ans += s[i];
    ans += t[i];
  }
  cout << ans << endl;
}