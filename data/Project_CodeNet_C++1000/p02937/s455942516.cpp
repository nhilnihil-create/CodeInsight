#include<bits/stdc++.h>
using namespace std;

signed main() {
  string s,t;
  cin >> s >> t;
  map<char,set<int>> mp;
  for(int i=0; i<s.size(); i++) {
    char c = s[i];
    if(mp.count(c)) mp[c].insert(i);
    else mp[c] = set<int>({i});
  }

  long long ans = 0;
  int pos = 0;
  for(auto c : t) {
    set<int>& p = mp[c];
    auto it = p.lower_bound(pos);
    if(it == p.end()) {
      ans += s.size();
      pos = 0;
      it = p.lower_bound(pos);
      if(it == p.end()) {puts("-1"); return 0;}
    }

    pos = (*it) + 1;
    //cout << c << " " << pos << " " << ans << endl;
  }
  ans += pos;
  cout << ans << endl;
}
