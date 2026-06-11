#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s, t; cin >> s >> t;
  vector<vector<ll>> l(26);
  for(int i = 0; i < (int)s.size(); i++){
    l[s[i] - 'a'].push_back(i+1);
  }
  ll ans = 0;
  ll cnt = 0;
  bool ok = true;
  for(int i = 0; i < (int)t.size(); i++){
    int tmp = t[i] - 'a';
    if(l[tmp].empty()){
      ok = false;
      break;
    }
    int num = lower_bound(l[tmp].begin(), l[tmp].end(), cnt+1) - l[tmp].begin();
    //cout << cnt << " " << num << endl;
    bool next = false;
    if(num == (int)l[tmp].size()){
      ans += s.size();
      cnt = 0;
      next = true;
    }
    if(next) num = lower_bound(l[tmp].begin(), l[tmp].end(), cnt) - l[tmp].begin();
    if(num < (int)l[tmp].size()){
      cnt = l[tmp][num];
    }
  }
  ans += cnt;
  if(!ok) cout << -1 << endl;
  else cout << ans << endl;
}