#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 10000000000000000;

int main(){
  cout << setprecision(10);
  int N,M; cin >> N >> M;
  int all = (1<<N) -1;
  cerr << all << endl;

  vector<ll> a(M);
  int b;
  vector<ll> c(M,0);
  for(int i = 0; i < M; i++){
    cin >> a[i] >> b;
    for(int j = 0; j < b; j++){
      int tmp; cin >> tmp;
      tmp--;
      c[i] += (1 << tmp);
    }

  }

  vector<vector<ll>> dp(M+1, vector<ll>(all+1, MAX));
  dp[0][0] = 0;

  for(int i = 0; i < M; i++){
    for(int j = 0; j <= all; j++){
      // iを使う場合
      dp[i+1][j|c[i]] = min(dp[i+1][j|c[i]], dp[i][j] + a[i]);
      // iを使わない場合
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
    }
  }

  cout << ( dp[M][all] == MAX ? -1 : dp[M][all] )  << endl;


}

