#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  string s;
  cin >> s;
  int l = s.length();
  vector<int> ans(l);
  vector<int> nr(l), nl(l);
  int pl = l, pr = 0;
  for(int i = l-1; i >= 0; i--) {
    if(s[i] == 'L') pl = i;
    else nl[i] = pl;
  }
  rep(i,l) {
    if(s[i] == 'R') pr = i;
    else nr[i] = pr;
  }
  rep(i,l) {
    if(s[i] == 'R') {
      int d = nl[i] - i;
      if(d % 2) ans[nl[i]-1]++;
      else ans[nl[i]]++;
    } else {
      int d = i - nr[i];
      if(d % 2) ans[nr[i]+1]++;
      else ans[nr[i]]++;
    }
  }
  rep(i,l) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
