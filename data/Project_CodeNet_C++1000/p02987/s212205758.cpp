#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void){//main関数
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if(s[0]==s[1] && s[1]==s[2]){
    //正直面倒だった
    cout << "No" << endl;
    return 0;
  }
  cout << ((s[0]==s[1] && s[2]==s[3]) || (s[0]==s[3] && s[1]==s[2])?"Yes":"No") << endl;
  return 0;
  //今日のノルマ達成！
}
