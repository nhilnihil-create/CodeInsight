#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  vector <ll> d(n), c(n);
  ll sum = 0;
  ll cnt = 0;
  for(int i = 0; i < n; i++) {
    cin >> d[i] >> c[i];
    sum += d[i] * c[i];
    cnt += c[i];
  }
  cout << (cnt - 1) + (sum - 1) / 9 << '\n';
}