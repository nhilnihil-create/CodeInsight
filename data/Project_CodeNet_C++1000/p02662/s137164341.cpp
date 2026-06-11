#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;
template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }

void inline TorF(bool tf, const string &trueMessage, const string &falseMessage) { 
  cout << (tf ? trueMessage : falseMessage) << endl;
}
void inline YESNO(bool tf) { TorF(tf, "YES", "NO"); }
void inline YesNo(bool tf) { TorF(tf, "Yes", "No"); }

ll dp[3020][3020];
const ll MOD = 998244353LL;
int main() {
  int N, S; cin>>N>>S;
  vector<ll> two(1,1);
  for(int i = 0; i < N; i++) two.push_back(two.back() * 2LL % MOD);
  vector<int> A(N);
  REP(i,N) cin>>A[i];
  dp[0][0] = two[N];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= S; j++) {
      dp[i+1][j] += dp[i][j];
      dp[i+1][j] %= MOD;
      const int u = j + A[i];
      if(u <= S) {
	ll v = dp[i][j];
	if(v % 2 == 0) v /= 2LL;
	else v = (v + MOD) / 2LL;
	dp[i+1][u] += v;
	dp[i+1][u] %= MOD;
      }
    }
    //    REP(j,S+1)
    //      cout << "(" << j << "," << dp[i+1][j] << ")";
    //    cout << endl;
  }
  cout << dp[N][S] << endl;
  return 0;
}
