#include <iostream>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
const LL mod=1000000007;

int main(){
  string L;
  cin >> L;
  LL N=L.size();
  LL ans=0;
  LL dp[100010][2]={0};
  dp[0][0]=2; dp[0][1]=1;
  rep(i,N-1){
    if(L[i+1]=='0'){
      dp[i+1][0]=dp[i][0];
      dp[i+1][1]=dp[i][1]*3%mod;
    }
    else{
      dp[i+1][0]=dp[i][0]*2%mod;
      dp[i+1][1]=(dp[i][1]*3+dp[i][0])%mod;
    }
  }
  ans+=dp[N-1][0]+dp[N-1][1];
  cout << ans%mod << endl;

  return 0;
}
