#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// abc141 E-Who Says a Pun?

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  string S; cin >> S;
  vector<vector<int> > dp(5005, vector<int>(5005, 0));
  int ans = 0;
  for(int i = N-1; i >= 0; i--){
    for(int j = N-1; j >= 0; j--){
      if(S[i] == S[j]) dp[i][j] = dp[i+1][j+1] + 1;
      if(i < j){
        int tmp = min(j-i, dp[i][j]);
        ans = max(ans, tmp);
      }
    }
  }
  cout << ans << endl;
}