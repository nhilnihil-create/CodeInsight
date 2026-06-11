#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(int i = (int)(k);i < (int)(n);i++)
int K, a = 1, b = 1;
vector<map<int, int>> dp(11);
void c() {
  while(K > dp[a][b]) {
    K -= dp[a][b];
    b++;
  }
  cout << b;
  if(0 < b) b--;
  a--;
}
int main() {
  cin >> K;
  vector<int> S(11);
  rep(i, 0, 10) dp[1][i] = 1;
  S[1] = 9;
  rep(i, 2, 11) rep(j, 0, 10) rep(k, -1, 2) {
    dp[i][j] += dp[i-1][j+k];
    if(j > 0) S[i] += dp[i-1][j+k];
  }
  while(K > S[a]) {
    K -= S[a];
    a++;
  }
  while(a > 0) c();
  cout << endl;
}