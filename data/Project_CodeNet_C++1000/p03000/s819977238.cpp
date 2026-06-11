#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, x;
  cin >> n >> x;
  ll d = 0, res = 1;
  rep(i, n) {
    ll l;
    cin >> l;
    d += l;
    if (d <= x) res++;
  }
  cout << res << endl;
}