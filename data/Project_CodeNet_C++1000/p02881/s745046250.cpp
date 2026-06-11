#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N;
  cin >> N;
  ll ans = N-1;
  for (ll i = 1; i * i <= N; i++) {
    if (N%i) continue;
    ll temp = i-1;
    temp += (N/i) - 1;      
    if (temp < ans) ans = temp;
  }
  cout << ans << '\n';  
  return 0;
}