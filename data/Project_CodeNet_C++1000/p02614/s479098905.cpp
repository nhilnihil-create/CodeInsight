#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<map>
#include<bitset>
#include<queue>
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  int ans = 0;
  rep(is,1<<h)rep(js,1<<w){
    int cnt = 0;
    rep(i,h)rep(j,w){
      if (is>>i&1) continue;
      if (js>>j&1) continue;
      if (s[i][j] == '#') cnt++;
    }
    if (cnt == k) ans++;
  }
  cout << ans << endl;
  return 0;
}
