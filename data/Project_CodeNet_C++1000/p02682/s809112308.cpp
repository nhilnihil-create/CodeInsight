#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll A,B,C,K;
  cin >> A >> B >> C >> K;
  ll ans = min(K,A);
  K -= ans;
  if (!K) {
    cout << ans << endl;
    return 0;
  }
  ll b = min(K,B);
  K -= b;
  if (!K) {
    cout << ans << endl;
    return 0;
  }
  cout << ans - min(K,C) << endl;
}
