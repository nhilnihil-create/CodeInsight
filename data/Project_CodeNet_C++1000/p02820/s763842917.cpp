#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n,k;
  int r,s,p;
  string t;
  cin >> n >> k;
  cin >> r >> s >> p;
  cin >> t;

  vector<string> enemy(k);
  for(int i = 0; i < n; i++){
    enemy[i%k].push_back(t[i]);
  }
  bool flag = 0;
  long long ans = 0;
  for(int i = 0; i < k; i++){
    for(int j = 0; j < enemy.at(i).size(); j++){
      // cout << enemy[i][j] << ",";
      if(j != 0 && enemy[i][j] == enemy[i][j-1] && flag == 0){
        flag = 1;
        continue;
      }
      flag = 0;
      if(enemy[i][j] == 'r') ans += p;
      else if(enemy[i][j] == 's') ans += r;
      else if(enemy[i][j] == 'p') ans += s;
    }
    // cout << endl;
  }

  cout << ans << endl;

  // long long ans = 0;
  // for(int i = 0; i < n; i++){
  //   if(i >= k-1 && t[i - k] == t[i]) continue;
  //   if(t[i] == 'r') ans += p;
  //   else if(t[i] == 's') ans += r;
  //   else if(t[i] == 'p') ans += s;
  // }
  // cout << ans << endl;

  return 0;
}