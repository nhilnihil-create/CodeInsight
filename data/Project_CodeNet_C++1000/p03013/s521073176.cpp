#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;


int main(){
  int N,M;
  cin >> N >> M;
  int a;
  int b[N];
  ll dp[N+1];
  for(int i=0;i<N;i++){
    b[i]=1;
    dp[i]=0;
  }
  for(int i=0;i<M;i++){
    cin >> a;
    b[a]=0;
  }
  if(N>1){
    dp[0]=b[0];
    dp[1]=b[1];
    for(int n=2;n<N+1;n++){
      dp[n]=dp[n-1]*b[n-1]+dp[n-2]*b[n-2];
      dp[n]=dp[n]%1000000007;
    }
    cout << dp[N] << endl;
  }else cout << b[0] << endl;
}
