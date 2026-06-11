#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

ll AN(ll A, ll N){
  if (N == 0){
    return 1;
  }else{
    if (N % 2 == 0){
      return AN((A*A)%nmax, N/2) % nmax;
    }else{
      return AN((A*A)%nmax, N/2) * A % nmax;
    }
  }
}


int main(){
  int N, M; cin >> N >> M;
  vector <int> S(N), T(M);
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int i = 0; i < M; i++) cin >> T[i];

  ll DP[N + 1][M + 1];
  for (int i = 0; i < N + 1; i++){
    for (int j = 0; j < M + 1; j++){
      DP[i][j] = 0;
      if (i == 0 || j == 0) DP[i][j] = 1;
    }
  }

  
  for (int i = 1; i < N + 1; i++){
    for (int j = 1; j < M + 1; j++){
      if (S[i - 1] == T[j - 1]){
        DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
      }else{
        DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1];
      }
      while (DP[i][j] < 0){
        DP[i][j] += nmax;
      }
      
      DP[i][j] %= nmax;
    }
  }

  cout << DP[N][M] << endl;
  
  return 0;
}
