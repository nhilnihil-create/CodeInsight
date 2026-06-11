#include<bits/stdc++.h>


using namespace std;


typedef long long int lli;
typedef long double ld;


const int MAXN = 302;
const lli INF = (lli)(1e16);


lli H[MAXN];
lli memo[MAXN][MAXN];


int main() {

  int N, K;

  cin >> N >> K;
  for (int i = 1 ; i <= N ; i++) {
    cin >> H[i];
  }

  
  for (int i = 1 ; i <= N ; i++) {
    memo[i][1] = H[i];
    for (int k = 2 ; k <= N ; k++) {
      memo[i][k] = INF;
    }
  }

  for (int k = 2 ; k <= N-K ; k++) {
    for (int i = 1 ; i <= N ; i++) {
      for (int j = i-1 ; j >= 1 ; j--) {
        memo[i][k] = min(memo[i][k], memo[j][k-1] + max((lli)0, H[i]-H[j]));
      }
      //cerr << "memo[" << i << "]" << k << "] = " << memo[i][k] << "\n";
    }
  }

  lli ans = INF;
  for (int i = 1 ; i <= N ; i++) {
    ans = min(ans, memo[i][N-K]);
  }
  
  cout << ans;


  return 0;
}
