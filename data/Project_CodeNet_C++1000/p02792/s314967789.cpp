#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<bool> vb;
long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
long long int min(long long int a,long long int b){
  if(a<b)
    return a;
  else
    return b;
}
long long int binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
    }
  return res;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
 
//############################ENDOFTEMPLATE############################
void solve(){
  int n;
  cin>>n;

  vector<vector<int>> dp(10,vector<int>(10));

  for(int i = 1;i<=n;i++){
    int f = i%10;
    int l;
    if(i<10)
      l = i;
    else{
      int cpy = i;
      while(cpy>=10){
        cpy/=10;
      }
      l = cpy;
    }
    dp[f][l]++;
  }

  lli ans = 0;
  for(int i = 1;i<=9;i++){
    for(int j = 1;j<=9;j++){
      ans = ans+(dp[i][j]*dp[j][i]);
    }
  }

  cout<<ans;
} 
 
 
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("moobuzz.in","r",stdin);
  //freopen("moobuzz.out","w",stdout);
  int t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}