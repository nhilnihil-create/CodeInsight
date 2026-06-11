#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

const int N_MAX = 310;

int N, K;
vector<ll> H;

vector<vector<ll>> dp;

ll dfs(int n, int k) {
  if (dp[n][k]!=-1) return dp[n][k];
  if (n<k) return dp[n][k] = LLINF;
  if (k==0) return dp[n][k] = 0;
  if (k==1) return dp[n][k] = H[n-1];
  ll result = LLINF;
  for (int i=k-1; i<n; i++) {
    result = min(result, dfs(i,k-1)+max((ll)0,H[n-1]-H[i-1]));
  }
  return dp[n][k] = result;
}

int main() {
  cin >> N >> K;
  dp.resize(N+1,vector<ll>(N+1,-1));
  rep(i,N) { int tmp; cin >> tmp; H.push_back(tmp); }
  // rep(i,N+1) { rep(j,N+1) cout << dfs(i,j) << " "; cout << endl; }
  ll result = LLINF; rep(i,N) result = min(result, dfs(i+1,N-K));
  cout << result << endl;
  return 0;
}
