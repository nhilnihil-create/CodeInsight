#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
using ll = long long;

int main() {
  ll n;
  cin >> n;
  std::vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, n-1) {
    if(a[i] - a[i+1] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
