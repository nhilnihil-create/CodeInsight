#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int)1e9 + 7;
const int N = 2005;
int dp[N][N];
int a[N];
int b[N];

void add(int &a, int b){  
  a += b;
  if(a >= MOD) a -= MOD;
  else if(a < 0) a += MOD;
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ )
    cin >> a[i];
  for(int i = 1; i <= m ; i ++ )
    cin >> b[i];
  for(int i = 0 ; i < N ; i ++ ){
    dp[0][i] = 1;
    dp[i][0] = 1;
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      add(dp[i][j],dp[i-1][j]);
      add(dp[i][j],dp[i][j-1]);
      add(dp[i][j],-dp[i-1][j-1]);
      if(a[i]==b[j]){
        add(dp[i][j],dp[i-1][j-1]);
      }
    }
  }
  cout << dp[n][m];
  return 0; 
}