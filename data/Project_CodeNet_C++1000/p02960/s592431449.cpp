#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define INF 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
//dp[i桁目まで見た時][現時点の数を13で割ったあまり] <- 0埋めしてから足していく
ll dp[1000000][20];
int main(){
  string s;
  cin >> s;
  int n = s.size();
  dp[0][0] = 1;
  rep(i,n)rep(j,13){
    if(s[i] == '?'){
      rep(k,10)dp[i + 1][(j * 10 + k) % 13] += dp[i][j] % INF;
    }
    else{
      int k = s[i] - '0';
      dp[i + 1][(j * 10 + k) % 13] += dp[i][j] % INF;
    }
  }
  cout << dp[n][5] % INF << endl;
  return 0;
}
