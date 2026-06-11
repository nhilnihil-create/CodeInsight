#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
  ll L, R;
  cin >> L >> R;
  ll mod = 2019;
  ll out = INF;
  if (R - L >= 2019) {
    cout << 0 << endl;
  } else {
    for (ll i = L; i < R; i++){
      for(ll j = i + 1; j <= R; j++){
        out = min(out, (i * j) % mod);
      }
    }
    cout << out << endl;
  }
  return 0;
}