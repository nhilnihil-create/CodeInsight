#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
struct Gauss {
  int LOGN, sz;
  vector<T> basis;

  Gauss(int LOGN): LOGN(LOGN), sz(0), basis(LOGN) {}

  void insert(T mask) {
    for (int i = LOGN - 1; i >= 0; i--) {
      if (mask & (1LL << i)) {
        if (!basis[i]) {
          basis[i] = mask;
          ++sz;
          return;
        } else {
          mask ^= basis[i];
        }
      }
    }
  }

  T getMax() {
    T ans{};
    for (int i = LOGN - 1; i >= 0; i--) {
      ans = max(ans, ans ^ basis[i]);
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> a(n);
  ll xorSum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    xorSum ^= a[i];
  }
  for (int i = 59; i >= 0; i--) {
    if (xorSum & (1LL << i)) {
      for (int j = 0; j < n; j++) {
        if (a[j] & (1LL << i)) a[j] -= (1LL << i);
      }
    }
  }
  Gauss<ll> g(60);
  for (int i = 0; i < n; i++) g.insert(a[i]);
  cout << g.getMax() + (xorSum ^ g.getMax()) << endl;
  return 0;
}


