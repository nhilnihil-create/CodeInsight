#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000;

int main(){
  cout << setprecision(10);
  int N, M;
  cin >> N >> M;
  int full = pow(2, N) -1;

  vector<vector<ll>>  dp(M, vector<ll>(full+1, MAX));

  vector<ll> a(M);
  vector<ll> b(M, 0);

  for(int i = 0; i < M; i++){
    int tmp;
    cin >> a[i] >> tmp;

    for(int j = 0; j < tmp; j++){
      int tmp1;
      cin >> tmp1;
      tmp1--;
      b[i] += pow(2, tmp1);
    }

  }

  // initialize
  for(int i = 0; i < M; i++){
    dp[i][0] = 0;
  }
  dp[0][b[0]] = a[0];
  // cerr << b[0] << " " << dp[0][b[0]] << endl;

  for(int i = 0; i < M-1; i++){
    for(int j = 0; j <= full; j++){
      // i+1を使う時
      dp[i+1][j | b[i+1]] = min(dp[i+1][j | b[i+1]], dp[i][j] + a[i+1]);
      // i+1 を使わない時
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
    }
  }


  if(dp[M-1][full] == MAX){
    cout << -1 << endl;
  } else {
    cout << dp[M-1][full]  << endl;
  }
}
