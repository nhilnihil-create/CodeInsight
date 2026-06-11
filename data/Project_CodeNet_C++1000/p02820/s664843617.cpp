#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int calc(const string& str, int R, int S, int P){
  if(str.size() == 0) return 0;

  vector<vector<int>> dp(3, vector<int>(str.size()+1, 0));

  int N = str.size();
  rep(i,N){
    rep(j,3){
      rep(k,3){
        if(j==k) continue;
        
        if(str[i] == 'r'){
          if(k==2){
            dp[k][i] = max(dp[k][i], P + (i-1>=0?dp[j][i-1]:0));
          }else{
            dp[k][i] = max(dp[k][i], 0 + (i-1>=0?dp[j][i-1]:0));
          }
        }
        else if(str[i] == 's'){
          if(k==0){
            dp[k][i] = max(dp[k][i], R + (i-1>=0?dp[j][i-1]:0));
          }else{
            dp[k][i] = max(dp[k][i], 0 + (i-1>=0?dp[j][i-1]:0));
          }
        }
        else{
          if(k==1){
            dp[k][i] = max(dp[k][i], S + (i-1>=0?dp[j][i-1]:0));
          }else{
            dp[k][i] = max(dp[k][i], 0 + (i-1>=0?dp[j][i-1]:0));
          }
        }
      }
    }
  }

  return max({dp[0][N-1], dp[1][N-1], dp[2][N-1]});
}

int main(){
  int N, K;
  cin >> N >> K;
  int R, S, P;
  cin >> R >> S >> P;
  string T;
  cin >> T;
  vector<string> v(K,"");
  rep(i,T.size()){
    v[i%K] += T[i];
  }

  int ret = 0;
  rep(i,K){
    ret += calc(v[i], R, S, P);
  }

  cout << ret << endl;
  
  return 0;
}
