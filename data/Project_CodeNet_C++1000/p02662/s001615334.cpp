#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC169 F - Knapsack for All Subsets
// 2020.06.23

ll MOD = 998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, S; cin >> N >> S;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }

  vector<vector<ll> > dp(3005, vector<ll>(3005, 0));
  dp[0][0] = 1;
  for(int i = 0; i < N; i++){
    for(int j = 0; j <= S; j++){
      if(j+A[i] <= S) dp[i+1][j+A[i]] = (dp[i+1][j+A[i]]+dp[i][j])%MOD;
      dp[i+1][j] = (dp[i+1][j]+dp[i][j]*2)%MOD; 
    }
  }
  ll ans = dp[N][S]%MOD;
  cout << ans << endl;
}