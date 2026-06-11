#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const int INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  int n,m;
  cin >> n >> m;
  vector<P> key;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    int s = 0;
    rep(j,b){
      int c;
      cin >> c;
      c--;
      s |= 1<<c;
    }
    key.emplace_back(s,a);
  }

  vector<int> dp(1<<n,INF);
  dp[0] = 0;
  rep(i,1<<n){
    rep(j,m){
      int s = i | key[j].first;
      int cost = dp[i] + key[j].second;
      chmin(dp[s],cost);
    }
  }
  int ans = dp.back();
  if(ans==INF){
    puts("-1");
    return 0;
  }
  cout << ans << endl;
  return 0;
}