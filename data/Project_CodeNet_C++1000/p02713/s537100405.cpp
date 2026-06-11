#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int K;
  cin >> K;
  int ans = 0;
  for (int i = 1; i <= K; i++){
    for (int j = 1; j <= K; j++){
      for (int k = 1; k <= K; k++){
        ans += gcd(gcd(i, j), k);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
