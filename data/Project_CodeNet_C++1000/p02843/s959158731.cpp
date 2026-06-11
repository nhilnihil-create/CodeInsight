#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
typedef long long ll;
typedef long double ld;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
  ll n,m,k,i,j,result=0,x;
  int dp[200010]={0};
  string s;
  
  cin >> x;
  dp[0] = 1;
  rep(i,x){
    if(dp[i]==1){
      for(j=100;j<=105;j++){
        dp[i+j]=1;
      }
    }
  }
  result = dp[x];
  cout << (result==1 ? 1 : 0) << endl;
  return 0;
}