#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

ll mod = 1000000007;
ll MAX = 100005;
int main(){
  string s;
  cin >> s;
  ll n = s.size();
  vector<vector<ll>> dp(MAX,vector<ll>(13,0));
  dp[0][0] = 1;
  ll digit = 1;
  ll count = 1;
  rep(i,n){
    digit %= 13;
    if(s[n-1-i]!='?'){
      int x = ctoi(s[n-1-i]);
      // cout << count << " " << x << endl;
      // count ++;
      x = (x*digit)%13;
      rep(j,13){
        ll id = (j+x)%13;
        dp[i+1][id] += dp[i][j];
      }
    }else{
      rep(t,10){
        int x = (t*digit)%13;
        // cout << count << " " << t << endl;
        // count ++;
        rep(j,13){
          ll id = (j+x)%13;
          dp[i+1][id] += dp[i][j];
        }
      }
    }
    rep(j,13){
      dp[i+1][j] %= mod;
    }
    digit *= 10;
  }
  cout << dp[n][5] << endl;
  
  return 0;
}