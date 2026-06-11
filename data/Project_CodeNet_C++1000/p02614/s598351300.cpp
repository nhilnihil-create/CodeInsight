#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll H, W, K, ans = 0; cin >> H >> W >> K;
  vector<vector<char>> C(H, vector<char>(W, '.'));
  rep(i, H) rep(j, W)
    cin >> C[i][j];
  rep(i, 1 << H){
    rep(j, 1 << W){
//      cout<<"i:"<<i<<" j:"<<j<<endl;
      vector<vector<char>> test;
      test = C;
      rep(k, H){
        if((i>>k) & 1)
          rep(x, W)
            test[k][x] = '.';
      }
      rep(k, W){
        if((j>>k) & 1)
          rep(y, H)
            test[y][k] = '.';
      }
      ll tmp = 0;
      rep(n, H) rep(m, W) 
        if (test[n][m] == '#')
          tmp++;
      if (tmp == K)
        ans++;
/*rep(i, H){
  rep(j, W)
    cout<<test[i][j];
  cout<<endl;
}
  cout<<endl;
*/   
//cout << tmp << endl;
    }
  }
  cout << ans << endl;
}

