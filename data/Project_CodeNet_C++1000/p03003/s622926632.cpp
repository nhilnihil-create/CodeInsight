#include<iostream>
using namespace std;

int N, M;
int S[2000], T[2000];
const long long mod = 1e9 + 7;
long long dp[2003][2003] = {};


int main(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> S[i];
  }
  for(int i = 0; i < M; i++){
    cin >> T[i];
  }

  for(int i = 1; i <= N + 1; i++){
    for(int j = 1; j <= M + 1; j++){
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
      if(i > 1 && j > 1 && S[i - 2] == T[j - 2]){
	dp[i][j] += 1 + dp[i - 1][j - 1];
      }
      dp[i][j] += mod;
      dp[i][j] %= mod;
    }
  }

  cout << (dp[N + 1][M + 1] + 1) % mod << endl;
}
