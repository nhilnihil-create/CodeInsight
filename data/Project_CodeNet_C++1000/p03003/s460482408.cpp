#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vector<ll> > vvl;
typedef vector<vector<P> > vvp;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  int n,m;
  cin >> n >> m;
  vector<ll>s(n),t(m);
  rep(i,n) cin >> s[i];
  rep(i,m) cin >> t[i];
  
  vvl dp(n+1,vl(m+1,0));
  
  rep(i,n){
    rep(j,m){
      dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1];
      if(s[i]==t[j]) dp[i+1][j+1]++;
      else{
        dp[i+1][j+1] -= dp[i][j];
        dp[i+1][j+1] += MOD;
      }
      dp[i+1][j+1] %= MOD;
    }
  }
  
  cout << dp[n][m]+1 << endl;
  
  return 0;     
}
