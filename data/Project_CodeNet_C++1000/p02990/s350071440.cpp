#include <bits/stdc++.h>
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
const int mod = 1e9+7;


ll C[2010][2010];

int main() {
  memset(C,0,sizeof C);
  rep(i,2010) {
    for(int j = 0; j <= i; j++) {
      if(j==0||j==i) C[i][j] = 1;
      else {
        C[i][j] = C[i-1][j]+C[i-1][j-1];
        C[i][j] %= mod;
      }
    }
  }
  ll n, k;
  cin >> n >> k;
  for(int i = 1; i <= k; i++) {
    if(n-k+1<i) cout << 0 << endl;
    else cout << C[n-k+1][i]*C[k-1][i-1]%mod << endl;
  }
  return 0;
}