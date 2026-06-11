#include<bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define Dcout(a) cout << setprecision(20) << a << endl
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using ll = long long;
using PAIR = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 1 << 29;
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/

/******** User-defined Function *******/
vector<int> a,b;
int dp[1005][10005];
/**************************************/

/********** Main()  function **********/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,n; cin >> h >> n;
  a.resize(n);
  b.resize(n);
  rep(i,n) cin >> a[i] >> b[i];

  rep(i,h+1) dp[0][i] = INF;

  for(int i=0; i<n; ++i){
    for(int j=0; j<=h; ++j){
      if(j - a[i] >0) dp[i+1][j] = min(dp[i][j], dp[i+1][j - a[i]] + b[i]);
      else dp[i+1][j] = min(dp[i][j],b[i]);
    }
  }
  
  cout << dp[n][h] << endl;

  // rep(i,30){
  //   rep(j,6){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}
/********  Main() Ends Here *************/
