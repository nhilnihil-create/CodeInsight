#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, K;
  cin >> N >> K;
  vector <int> H(N);
  rep(i,N) cin >> H[i];
  sort(all(H));
  K = min(K, N);
  rep(i,K) H.pop_back();
  ll ans = 0;
  rep(i,H.size()) ans += H[i];
  cout << ans << endl;
  return 0;
}
