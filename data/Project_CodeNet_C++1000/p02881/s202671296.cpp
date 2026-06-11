#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll N;
  cin >> N;
  ll ans = 1e15;
  for (ll i = 1; i * i <= N; i ++) {
    if (N % i == 0) {
      ll kj = i + (N / i) - 2;
      if (ans > kj) ans = kj;
    }
  }
  cout << ans << endl;
}