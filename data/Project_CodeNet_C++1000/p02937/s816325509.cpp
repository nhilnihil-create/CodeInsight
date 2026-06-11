#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main(){
  long long a = 0;
  string s, t; cin >> s >> t; s += s;
  vector<vector<int>> m(26), v(26, vector<int>((int)s.size(), -1));
  rep(i, s.size()) m[s[i]-'a'].push_back(i);
  rep(i, 26){
    if(m[i].size() == 0) continue;
    else rep(j, (int)s.size()/2) v[i][j] = m[i][upper_bound(m[i].begin(), m[i].end(), j)-m[i].begin()]-j;
  }
  rep(i, t.size()){
    if(m[t[i]-'a'].size() == 0){
      a = -2; break;
    }
    else if(i == 0 && s[0] == t[i]) continue;
    else a += v[t[i]-'a'][a % ((int)s.size()/2)];
  }
  cout << a+1 << "\n";
  return 0;
}