#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  INT(N);
  INT(M);
  vector<P> vec(M);
  REP(i,M){
    int a,b;
    cin >> a >> b;
    vec[i].fi=a;
    int cnt = 0;
    REP(j,b){
      int x;
      cin >> x;
      x--;
      cnt+=pow(2,x);
    }
    vec[i].se=cnt;
  }

  vector<vector<ll>> dp(1010,vector<ll>(4200,INF));
  dp[0][0]=0;
  REP(i,M){
    REP(j,1<<N){
      chmin(dp[i+1][j|vec[i].se],dp[i][j]+vec[i].fi);
      chmin(dp[i+1][j],dp[i][j]);
    }
  }

  if(dp[M][(1<<N)-1]<1000000000){
    cout << dp[M][(1<<N)-1] << endl;
  }else{
    cout << -1 << endl;
  }
}