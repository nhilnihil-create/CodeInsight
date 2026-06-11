#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,m;
  cin >> n >> m;
  int s[n];
  int t[m];
  rep(i,n)cin >> s[i];
  rep(i,m)cin >> t[i];
  ll p=1000000007;
  ll dp[n+1][m+1];
  rep(i,n+1)rep(j,m+1)dp[i][j]=0;
  rep(i,n+1)dp[i][0]=1;
  rep(i,m+1)dp[0][i]=1;
  rep(i,n){
    rep(j,m){
      if(s[i]==t[j])dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1])%p;
      else dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j]+p-dp[i][j])%p;
    }
  }
  cout << dp[n][m] << endl;
}
