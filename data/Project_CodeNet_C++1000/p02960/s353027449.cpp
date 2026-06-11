#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ld long double
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  string s;
  cin >> s;
  ll p=1000000007;
  ll n=s.size();
  ll dp[n+1][13];
  rep(i,n+1)rep(j,13)dp[i][j]=0;
  ll m=13;
  dp[0][0]=1;
  rep(i,n){
    if(s[i]=='?'){
      rep(j,10){
        rep(o,13){
          dp[i+1][(o*10+j)%m]=(dp[i+1][(o*10+j)%m]+dp[i][o])%p;
        }
      }
    }
    else{
      int y=(s[i]-'0');
      rep(o,13){
        dp[i+1][(o*10+y)%m]=(dp[i+1][(o*10+y)%m]+dp[i][o])%p;
      }
    }
  }
  ll ans=dp[n][5];
  cout << ans%p << endl;
} 
