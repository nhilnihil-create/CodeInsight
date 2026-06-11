#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, a, n) for(int i=a; i<n; i++)
#define ll long long
#define all(x) begin(x), end(x)
#define toInt(x) (x - '0')
#define pll pair<ll, ll>
#define pli pair<ll, int>
// #define int long long
const int inf = 1 << 30;
#define INF 1e+9
#define MAX_V 100008
const int MOD = 1e9 + 7;


signed main(){
  int n; cin >> n;
  vector<int> a(n);
  vector<vector<pair<int, int>>>  vp(n);
  for (int i=0; i<n; i++){
    cin >> a[i];
    for (int j=0; j<a[i]; j++){
      int x, y;
      cin >> x >> y;
      x--;
      vp[i].emplace_back(x, y);
    }
  }

  int ans = 0;
  for (int bit=0; bit < (1 << n); bit++){
    int tmp = 0;
    vector<int> S;
    bool flag = true;
    for (int i=0; i<n;i++){
      if(bit & (1 << i)){
        for (int j=0; j<vp[i].size(); j++){
          if (((bit >> (vp[i][j].first) & 1)) ^ vp[i][j].second){
          //   cout << bit << endl;
          //   cout << i << " " << j << " " << vp[i][j].first << vp[i][j].second << endl;
            flag = false;
          }
        }
      }
    }
    if (flag) ans = max(ans, __builtin_popcount(bit));
  }

  // cout << (5 & (1 << 1)) << endl;
  cout << ans << endl;
}
