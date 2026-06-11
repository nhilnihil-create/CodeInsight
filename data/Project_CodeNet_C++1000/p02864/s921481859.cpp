#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll dp[310][310] = {0};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<ll> H(N+1);
  H[0] = 0;
  for(int i = 1; i < N+1; i++){
    cin >> H[i];
  }

  for(int i = 0; i < N+1; i++){
    for(int j = 0; j < N+1; j++){
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;
  for(int i = 1; i < N+1; i++){
    for(int j = 1; j < N+1; j++){
      for(int k = 0; k < i; k++){
        chmin(dp[i][j], dp[k][j-1] + max(0LL, H[i] - H[k]));
      }
    }
  }

  ll ans = INF;
  for(int i = 0; i <= N; i++){
    chmin(ans, dp[i][N-K]);
  }

  cout << ans << endl;

  return 0;
}
