#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  int ans = 0;
  rep(is,1<<h)rep(js,1<<w) {
    int cnt = 0;
    rep(i,h)rep(j,w) {
      if (is>>i&1) continue;
      if (js>>j&1) continue;
      if (s[i][j] == '#') cnt++;
    }
    if (cnt == k) ans++;
  }
  cout << ans << endl;
  return 0;
}