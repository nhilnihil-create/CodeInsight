#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  string s, t; cin >> s >> t;
  map<char, set<int>> mp;
  vector<vector<int>> v(26);
  rep(i,s.size()){
    v[s[i] - 'a'].push_back(i);
  }
  int id = -1;
  ll ans = 0;
  rep(i,t.size()){
    int x = t[i] - 'a';
    if(v[x].size() == 0){
      cout << -1 << endl;
      return 0;
    }
    auto it = upper_bound(v[x].begin(), v[x].end(), id);
    if(it == v[x].end()){
      ans += s.size();
      id = *(v[x].begin());
    }
    else{
      id = *it;
    }
  }
  ans += id + 1;
  cout << ans << endl;
  return 0;
}
