#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
using pii = pair<ll, ll>;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}
int main() {
  ll n;
  cin >> n;
  vi a(n);
  vi b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (n % 2) {
    cout << b[n / 2] - a[n / 2] + 1 << endl;
  } else {
    cout << ((b[n / 2] + b[n / 2 - 1]) - (a[n / 2] + a[n / 2 - 1])) + 1
         << endl;
  }

  return 0;
}
