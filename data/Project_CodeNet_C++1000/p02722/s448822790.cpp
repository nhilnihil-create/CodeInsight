#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

vector<ll> divisors(ll n) {
  vector<ll> D;
  for (ll i=1; i*i<=n; i++) {
    if (n%i==0) {
      D.push_back(i);
      if (i*i!=n) D.push_back(n/i);
    }
  }
  return D;
}

int main() {
  ll n; cin >> n;
  multiset<ll> S;
  auto D = divisors(n);
  for (auto d: D) {
    ll m = n;
    if (d == 1) continue;
    while (m%d==0) m /= d;
    if (m==1) {
      S.insert(d);
      continue;
    }

    auto D2 = divisors(m-1);
    for (auto d2: D2) {
      if (d2 == 1) continue;
      if (d == d2) S.insert(d2);
    }
  }

  auto D3 = divisors(n-1);
  for (auto &&d3: D3) {
    if (d3 == 1) continue;
    S.insert(d3);
  }
  cout << S.size() << endl;
  return 0;
}
