#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,29)-1;

const int M_MAX = 2000;
const int N_MAX = 2000;

int main() {
  int N, M; cin >> N >> M;
  int S[N]; rep(i,N) cin >> S[i];
  int T[M]; rep(i,M) cin >> T[i];

  ll sum[N+1][M+1]={}; 
  rep(i,N+1) sum[i][0] = 1; rep(i,M+1) sum[0][i] = 1;
  rep(i,N) rep(j,M) {
    ll tmp = sum[i+1][j] + sum[i][j+1];
    if (S[i]!=T[j]) tmp -= sum[i][j];
    tmp = (tmp%MOD+MOD)%MOD;
    sum[i+1][j+1] = tmp;
  }

  // rep(i,N+1) { rep(j,M+1) cout << sum[i][j] << " "; cout << endl; }
  cout << sum[N][M] << endl;
  return 0;
}