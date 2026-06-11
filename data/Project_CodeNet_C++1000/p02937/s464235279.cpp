#include <bits/stdc++.h>
using namespace std;
int main () {
  string s, t;
  cin >> s >> t;
  vector<long> base(26, -1);
  vector<vector<long>> data(s.size() + 1, vector<long> (26, -1));
  for(int i = s.size(); i >= 0; i--){
    for(int j = 0; j < 26; j++)data.at(i).at(j) = base.at(j);
    if(i != 0)base.at(s.at(i - 1) - 'a') = i;
  }
  for(int i = s.size(); i >= 0; i--){
    for(int j = 0; j < 26; j++){
      if(data.at(i).at(j) == -1)data.at(i).at(j) = base.at(j);
    }
  }
  long ans = 0, pl = 0;
  for(int i = 0; i < t.size(); i++){
    if(data.at(pl).at(t.at(i) - 'a') != -1){
      if(data.at(pl).at(t.at(i) -'a') <= pl){
        ans += s.size();
      }
      pl = data.at(pl).at(t.at(i) -'a');
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans + pl << endl;
  return 0;
}