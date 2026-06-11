#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  string s; cin >> s;

  string c;
  int ans = 0;
  rep(i, 10) rep(j, 10) rep(k, 10){
    c[0] = i + '0';
    c[1] = j + '0';
    c[2] = k + '0';
    int id = 0;
    rep(si, n){
      if(s[si] == c[id]){
        id++;
        if(id == 3) break;
      }
    }
    if(id == 3) ans++;
  }
  cout << ans << endl;


  return 0;
}
