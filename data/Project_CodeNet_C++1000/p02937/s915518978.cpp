#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main(){
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int> > data(26);
  for(int i = 0; i < n; i++) data[s[i] - 'a'].push_back(i);
  for(int i = 0; i < 26; i++) data[i].push_back(INF);
  for(int i = 0; i < m; i++){
    if(data[t[i] - 'a'].size() == 1){
      cout << -1 << endl;
      return 0;
    }
  }
  int id = -1, cnt = 0;
  for(int i = 0; i < m; i++){
    int num = t[i] - 'a';
    int next = *upper_bound(data[num].begin(), data[num].end(), id);
    if(next == INF){
      cnt++;
      id = data[num][0];
    }
    else{
      id = next;
    }
  }
  ll ans = ll(n) * ll(cnt) + ll(id + 1);
  printf("%lld\n", ans);
}
