#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll n, k;
  cin >> n >> k;

  set<ll> s;
  for (long i = 0; i < k; i++) {
    ll d;
    cin >> d;
    for (long j = 0; j < d; j++) {
      ll a;
      cin >> a;
      s.insert(a);
    }
  }

  cout << n - s.size() << endl;
}
