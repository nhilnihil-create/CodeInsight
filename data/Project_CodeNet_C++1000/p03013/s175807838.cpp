#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

const int MOD = 1e9+7;

ll dp[100010];

int main(){
  int n, m;
  cin >> n >> m;
  map<int,int> a;
  rep(i,m){
    int A;
    cin >> A;
    a[A]++;
  }
  rep(i,n+1){
    dp[i]=0;
  }
  for(int i = 1; i <= n; i++){
    if(a[i] == 1) dp[i]=0;
    else{
      if(i == 1) dp[i] = dp[i-1] + 1;
      else if(i == 2) dp[i] = dp[i-2] + 1 + dp[i-1];
      else dp[i] = dp[i-2] + dp[i-1];
    }
    dp[i]%=MOD;
  }
  cout<<dp[n]<<endl;
}