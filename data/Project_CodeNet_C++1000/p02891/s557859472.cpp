#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int , int>;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s; ll k; cin >> s >> k;
  ll cnt = 0;
  int l = 0, r = 0;
  int j = 0;
  
  if(s[0] == s[s.size()-1]) {
    ++l;
    while(s[j] == s[++j]) ++l;
    j = s.size()-1;
    if(l == s.size()) {
      cout << s.size() * k / 2 << endl;
      return 0;
    }
    ++r;
    while(s[j] == s[--j]) ++r;
  }
  for(int i = l; i < s.size()-r; ++i) {
    bool b = s[i] == s[i-1];
    cnt += b;
    if(b) s[i] = '#';
  }
  cout << l/2 + cnt * k + (l + r) / 2 * (k - 1) + r/2 << endl;
}
