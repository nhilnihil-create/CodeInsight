#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  int ans = 0;
  rep(i, 10)rep(j, 10)rep(k, 10){
    int idx = 0;
    rep(l, n){
      int cy[3] = { i, j, k };
      if ((s[l]-'0') == cy[idx]) idx++;
      if (idx == 3){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}