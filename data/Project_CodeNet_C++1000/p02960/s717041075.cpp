#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}
int gyaku(int n){
    return modpow(n,MOD-2);
}
signed main() {
  string s;
  cin>>s;
  int n=s.size();
  int dp[100001][13];
  rep(i,100001)rep(j,13)dp[i][j]=0;
  dp[0][0]=1;
  int m=1;
  rep(i,s.size()){
    if(s[n-1-i]=='?'){
      rep(j,13)rep(k,10){
        dp[i+1][(j+(k*m))%13]=(dp[i+1][(j+(k*m))%13]+dp[i][j])%MOD;
      }
    }
    else{
      int t=s[n-1-i]-'0';
      rep(j,13)dp[i+1][(j+t*m)%13]=dp[i][j];
    }
    m=10*m%13;
  }
  cout<<dp[s.size()][5]<<endl;
}
