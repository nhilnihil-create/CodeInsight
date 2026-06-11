#include <bits/stdc++.h>
//#include <chrono>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

typedef long long ll ;

const ll MOD = 1000000007;

ll dp[2100][2100];

int main() {

//  std::chrono::system_clock::time_point  start, end; // 型は auto で可
//  start = std::chrono::system_clock::now(); // 計測開始時間

  int N,M;
  cin >> N >> M;
  vector< int > S(N+3),T(M+3);
  REP(i,N) cin >> S[i];
  REP(i,M) cin >> T[i];

  REP(si, N+1)
    REP(ti, M+1)
      dp[si][ti] = 0;
  
  dp[0][0] = 1;

  REP(si, N+1) {
    REP(ti, M+1) {
      if (ti-1>=0 && si-1>=0 ) {
        if (S[si-1] == T[ti-1]) dp[si][ti] = (dp[si][ti] + dp[si-1][ti-1]) % MOD;
      }
      if (si-1>=0) dp[si][ti] = (dp[si][ti] + dp[si-1][ti]) % MOD;
      if (ti-1>=0) dp[si][ti] = (dp[si][ti] + dp[si][ti-1]) % MOD;
      if (ti-1>=0 && si-1>=0) {
        if ( dp[si][ti] - dp[si-1][ti-1] < 0 ) {
          dp[si][ti] += MOD;
        }
        dp[si][ti] = (dp[si][ti] - dp[si-1][ti-1]);
      }
    }
  }
  cout << dp[N][M] << endl;

  /*
  REP(si, N+1) {
    REP(ti, M+1) {
      cout << dp[si][ti];
    }
    cout << endl;
  }
  cout << endl;
    */
  
// end = std::chrono::system_clock::now();  // 計測終了時間
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
// std::cout << elapsed << " ms" << std::endl;

}

