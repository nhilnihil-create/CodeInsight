#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)

constexpr int mod = 1e9+7;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  int dp[3] = {0};
  ll ans = 1;
  REP(i, N){
    int cnt = 0;
    int id = 0;
    REP(j, 3){
      if(dp[j] == A[i]){
        cnt++;
        id = j;
      }
    }
    ans *= cnt;
    ans %= mod;
    dp[id]++;
  }
  cout << ans << endl;
  return 0;
}
