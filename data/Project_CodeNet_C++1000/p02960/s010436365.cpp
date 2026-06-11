#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  string s;
  cin >> s;
  ll k=s.size();
  vvl dp(k+1,vl(13));
  dp[0][0]=1;
  rep(i,12){
    dp[0][i+1]=0;
  }
  ll a=1;
  rep(i,k){
    rep(j,13){
      if(s[k-i-1]=='?'){
        rep(l,10){
          dp[i+1][(j+a*l)%13]+=dp[i][j];
          dp[i+1][(j+a*l)%13]%=MOD;
        }
      }
      else{
        ll x=a*(s[k-i-1]-'0')%13;
        dp[i+1][(j+x)%13]+=dp[i][j];
        dp[i+1][(j+x)%13]%=MOD;
      }
    }
    a*=10;
    a%=13;
  }
  cout << dp[k][5] << endl;
}