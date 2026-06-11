#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<vector<ll>>data(10,vector<ll>(10,0));
  rep(i,0,10) rep(j,0,10){
    rep(k,1,n+1){
      string s = to_string(k);
      if(s[0]-'0' == i && s[s.size()-1]-'0' == j) data[i][j]++;
    }
  }
  rep(i,0,10) rep(j,0,10) ans += data[i][j]*data[j][i];
  cout << ans << endl;
}