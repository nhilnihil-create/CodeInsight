#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
//#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;


int main() {
  int N, M; cin >> N >> M;
  vector<ll> S(N);
  rep(i, 0, N) cin >> S[i];
  vector<ll> T(M);
  rep(i, 0, M) cin >> T[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(M + 1,0));
  vector<vector<ll>> acum(N + 1, vector<ll>(M + 1, 0));
  ll ans = 0;

  rep(i, 0, N){
    rep(k, 0, M){
      if(S[i] == T[k]) dp[i + 1][k + 1] = acum[i][k] + 1 % MOD;
      else dp[i + 1][k + 1] = 0;
      acum[i + 1][k + 1] = acum[i][k + 1] + acum[i + 1][k] - acum[i][k] + dp[i + 1][k + 1] % MOD;
      ans += dp[i + 1][k + 1];
      ans %= MOD;
    }
  }

  ans = ans + 1 % MOD;

  cout << ans << endl;

}