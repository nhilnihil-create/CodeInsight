#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

const ll MOD = (ll)pow(10,9)+7;

int main(){
  int s;
  cin >> s;
  vector<vector<ll>> pas(2001,vector<ll>(2001));
  pas[0][0] = 1;
  rep(i,2000){
    rep(j,2000){
      pas[i+1][j] += pas[i][j];
      pas[i+1][j] %= MOD;
      pas[i+1][j+1] += pas[i][j];
      pas[i+1][j] %= MOD;
    }
  }
  ll ans = 0;
  for(int i=1;3*i<=2000;i++){
    if(s < i*3) break;
    int h = s - 3*i;
    ans += pas[h+i-1][i-1];
    ans %= MOD;
  }
  cout << ans << endl;
}
