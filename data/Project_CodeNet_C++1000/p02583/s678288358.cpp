#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef complex<ll> P;
#define real X
#define imag Y

bool check(ll a, ll b, ll c) {
  return (a + b > c) && (a + c > b) && (b + c > a) && a != b && a != c && b != c && a <= b && b <= c;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      for (int k = 0; k < n; ++k) {
	if (k == i || k == j) continue;
	if (check(a[i], a[j], a[k])) {
	  ++ans;
	}
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
