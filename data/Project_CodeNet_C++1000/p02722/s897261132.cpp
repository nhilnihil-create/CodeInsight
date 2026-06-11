#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  set<ll> factors1, factors2;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      factors1.insert(i);
      if (i * i != n) factors1.insert(n / i);
    }
    if ((n-1) % i == 0) {
      factors2.insert(i);
      if (i * i != n-1) factors2.insert((n-1) / i);
    }
  }

  ll cnt = factors2.size() - 1;
  ll n1;
  for (ll f: factors1) {
    if (f == 1) continue;
    //cout << f << endl;
    n1 = n;
    while (n1 % f == 0) n1 /= f;
    if (n1 % f == 1) cnt++;
  }
  cout << cnt << endl;
}
