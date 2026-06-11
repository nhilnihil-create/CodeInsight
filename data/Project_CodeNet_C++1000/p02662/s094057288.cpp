#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define MOD 998244353LL
long long best[3030][3030];
long long v[4444], N, S;
int main() {

  cin >> N >> S;
  for(int i=1;i<=N;++i) {
    cin >> v[i];
  }
  best[0][0] = 1;
  for(int i=0;i<N;++i) {
    for(int j=0;j<=S;++j) {
      if ( best[i][j] == 0) continue;
      int n = j + v[i+1];
     // cout << n << " " << i << endl;
      if(n <= S) {
        best[i+1][n] += best[i][j];
        best[i+1][n] %= MOD;
      }
      best[i+1][j] += best[i][j] * 2;
      best[i+1][j] %= MOD;
    }
  }
 // cout << best[N][0] << endl;
  cout << best[N][S] << endl;
}