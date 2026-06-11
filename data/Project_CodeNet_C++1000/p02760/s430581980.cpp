#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  vector<int> card(9);
  vector<bool> map(9,false);
  rep(i,9) cin >> card[i];
  int n; cin >> n;
  int num;
  rep(i,n){
    cin >> num;
    rep(j,9) if(card[j] == num) map[j] =true;
  }

  //cout << map[0] << " " << map[1] << " " << map[2] << endl;
  //cout << map[3] << " " << map[4] << " " << map[5] << endl;
  //cout << map[6] << " " << map[7] << " " << map[8] << endl;
  string ans = "No";
  if(map[0] && map[1] && map[2]) ans = "Yes";
  if(map[3] && map[4] && map[5]) ans = "Yes";
  if(map[6] && map[7] && map[8]) ans = "Yes";

  if(map[0] && map[3] && map[6]) ans = "Yes";
  if(map[1] && map[4] && map[7]) ans = "Yes";
  if(map[2] && map[5] && map[8]) ans = "Yes";

  if(map[0] && map[4] && map[8]) ans = "Yes";
  if(map[2] && map[4] && map[6]) ans = "Yes";

  cout << ans << endl;
}
