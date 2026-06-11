#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
//const ll MOD=1000000007;
const ll MOD=998244353;

ll dp[3030][3030];

int main(){
  int N,S; cin>>N>>S;
  int A[N]; rep(i,N) cin>>A[i];
  dp[0][0]=1;
  rep(i,N) rep(j,S+1){
    (dp[i+1][j]+=dp[i][j]*2)%=MOD;
    if(j+A[i]>S) continue;
    (dp[i+1][j+A[i]]+=dp[i][j])%=MOD;
  }
  cout<<dp[N][S]<<endl;
  return 0;
}