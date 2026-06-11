#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)

const long long mod=1e9+7;

int main(){
  int n,m;	cin >> n >> m;
  vector<bool>	a(n+1,true);
  rep(i,m){
    int x;	cin >> x;
    a[x]=false;
  }
  
  vector<long long>	dp(n+1);
  dp[0]=1;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<=min(n,i+2);j++){
      if(a[j]){
        dp[j]+=dp[i];
        dp[j]%=mod;
      }
    }
  }
  cout << dp[n];
}