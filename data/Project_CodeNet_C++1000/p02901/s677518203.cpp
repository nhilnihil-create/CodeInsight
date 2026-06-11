#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n,m;
  cin >> n >> m;
  vector<P> key;
  rep(i,0,m){
    int a,b;
    cin >> a >> b;
    int s = 0;
    rep(i,0,b){
      int c;
      cin >> c;
      c--;
      s |= 1<<c;
    }
    key.emplace_back(a,s);
  }
  vint dp(1<<n,INF);
  dp[0] = 0;
  rep(i,0,1<<n){
    rep(j,0,m){
      int s = key[j].second|i;
      int cost = dp[i] + key[j].first;
      dp[s] = min(dp[s],cost);
    }
  }
  int ans = dp.back();
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}