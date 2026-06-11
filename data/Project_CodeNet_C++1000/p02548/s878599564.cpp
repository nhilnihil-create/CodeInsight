#include<iostream>
using namespace std;
typedef long long ll;
int main () {
  ll N;
  cin >> N;
  ll ans = 0;
  for (ll i = 1ll; i < N; i ++) {
    ans += ((N - 1) / i);
  }
  cout << ans << endl;
}
