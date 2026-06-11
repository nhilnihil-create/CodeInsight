#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  ll n, r = 0, g = 0, b = 0;
  cin >> n;
  string s;
  cin >> s;
  rep(i,n) {
    if(s[i]=='R') r++;
    else if(s[i]=='G') g++;
    else b++;
  }
  ll ans = r*g*b;
  int i = 1;
  while(2*i<n) {
    for(int j = 0; j+2*i < n; j++) {
      if(s[j]==s[j+i]) continue;
      if(s[j]==s[j+2*i]) continue;
      if(s[j+i]==s[j+2*i]) continue;
      ans--;
    }
    i++;
  }
  cout << ans << endl;
  return 0;
}