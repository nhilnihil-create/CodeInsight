#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

int dp[2][2][1000100];

signed main(){
  int N;
  cin >> N;

  dp[0][0][0] = 1;
  for( int i = 1; i <= N; i++ ){
    for( int z = 0; z < 2; z++ ){
      for( int n = 0; n < 2; n++ ){
        for( int num = 0; num < 10; num++ ){
          int zfg = z;
          int nfg = n;
          if( num == 0 ) zfg = 1;
          if( num == 9 ) nfg = 1;
          dp[zfg][nfg][i] += dp[z][n][i-1];
          dp[zfg][nfg][i] %= MOD;
        }
      }
    }
  }
  cout << dp[1][1][N] << endl;

}
