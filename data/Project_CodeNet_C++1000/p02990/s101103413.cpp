#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
typedef long long ll;
using namespace std;

int main() {
  ll n,k,c[2007][2007];
  ll m = 1e9+7;
  cin >> n >> k;

  rep(i,n+1) c[0][i] =0;
  

  for(int i=0;i<=n;i++){
      c[i][0]=1;
      for(int j=1;j<=i;j++){
          c[i][j] = (c[i-1][j-1] + c[i-1][j]) % m;
      }
  }

  for(int i=1;i<=k;i++) cout << c[n-k+1][i] * c[k-1][i-1] % m << endl;


}