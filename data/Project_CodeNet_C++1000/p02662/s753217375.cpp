#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll MOD = 998244353;

// あとで S+1 までループを回しているため
ll DP[3001][3001];

// A の部分集合 T、Tの部分集合 U で数える
int main() {
  int N, S;
  cin >> N >> S;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];

  DP[0][0] = 1;
  REP(i, N) REP(j, S + 1) {
    // Ai が T に選ばれない場合
    DP[i + 1][j] += DP[i][j];
    // Ai が T には選ばれているが U には選ばれていない場合
    DP[i + 1][j] += DP[i][j];
    DP[i + 1][j] %= MOD;
    // Ai が選ばれた場合
    if (A[i] + j <= S) {
      DP[i + 1][j + A[i]] += DP[i][j];
      DP[i + 1][j + A[i]] %= MOD;
    }
  }
  cout << DP[N][S] << endl;
}