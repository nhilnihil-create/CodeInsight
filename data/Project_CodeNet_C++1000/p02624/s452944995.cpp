#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

// ll f(int n){
//   return n * (n + 1) / 2;
// }

int main(void){
  int N;
  cin >> N;
  ll ans = 0;
  for (int i = 1; i <= N; i++){
    ll k = N / i;
    ans += k * (k + 1) / 2 * i;
  }
  cout << ans << endl;
  return 0;
}
