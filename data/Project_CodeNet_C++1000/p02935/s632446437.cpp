#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double Pow(ll a, ll n) {
  if (n == 1) return a;
  if (n % 2 == 1) return (a * Pow(a, n-1));
  ll t = Pow(a, n/2);
  return t*t;
}

int main() {
  int N;
  cin >> N;
  vector<long double> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long double ans = 0;
  for (int i = 0; i < N-1; i++) {
    long double div = Pow(2, i+1);
    long double tmp = v[i]/div;
    ans += tmp;
  }
  ans += v[N-1] / Pow(2, N-1);
  cout << ans << endl;
}
