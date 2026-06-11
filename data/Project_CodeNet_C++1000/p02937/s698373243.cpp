#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  string s,t;cin >> s >> t;
  vector<vector<int>> G(26);

  s = s+s;
  int ch;
  rep(i,s.size()){
    ch = s[i] - 'a';
    G[ch].push_back(i+1);
  }

  ll ans = 0;
  int temp;
  if(s.find(t[0]) == string::npos) {
    cout << -1 << endl;
    return 0;
  }else {
    temp = G[t[0] - 'a'][0];
    ans += temp;
  }
  //cout << ans << endl;


  for(int i = 1;i < t.size();i++){
    if(s.find(t[i]) == string::npos){
      cout << -1 << endl;
      return 0;
    }

    ch = t[i] - 'a';
    //cout << ch << " " << G[ch][0] << endl;
    vector<int>::iterator it = upper_bound(G[ch].begin(),G[ch].end(),temp);
    ans += *it - temp;
    temp = *it%(s.size()/2);
    //cout << ans << endl;
  }

  cout << ans << endl;
}