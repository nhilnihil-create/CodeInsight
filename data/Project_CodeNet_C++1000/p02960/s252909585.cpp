#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

ll powmod(ll a,ll n,ll m) {
    if(n == 0)
        return 1;

    if(n % 2 ==0){
        ll r = powmod(a,n/2,m);
        return r*r % m;
    }

    return a*powmod(a,n-1,m)%m;
}

int main(){

  string s;
  cin >> s;
  ll n=s.size();

  ll dp[n][13];
  memset(dp,0,sizeof(dp));


  if(s[n-1]!='?'){
    ll a;
    a=ctoi(s[n-1]);
    dp[n-1][a]=1;
  }
  else{
    for(int j=0;j<10;j++){
      ll a=j;
      dp[n-1][a]=1;
    }
  }

  
  for(int i=n-2;i>=0;i--){
    if(s[i]!='?'){
      ll a;
      a=ctoi(s[i]);
      a=a*powmod(10,n-i-1,13)%13;
      for(int k=0;k<13;k++){
        dp[i][(k+a)%13]+=dp[i+1][k];
        dp[i][(k+a)%13]%=mod;
      }
    }
    else{
      for(int j=0;j<10;j++){
        ll a=j;
        a=a*powmod(10,n-i-1,13)%13;
        for(int k=0;k<13;k++){
          dp[i][(k+a)%13]+=dp[i+1][k];
          dp[i][(k+a)%13]%=mod;
        }
      }
    }
  }

  cout << dp[0][5] << endl;
  


}