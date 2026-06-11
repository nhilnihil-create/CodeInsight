#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long f(int n) {
  return (long long)(n <= 1 ? 0 : (ll)(n * (ll)(n-1)) / 2);
}

int main() {
  ll n; cin >>n;
  vector<ll> a(n);
  map<ll, ll> b;
  for (int i = 0; i < n; i++) {
    cin >>a[i];
    b[a[i]]++;
  }

  ll ret = 0;
  map<ll, ll> c, d;
  for (auto i : b) {
    ret += f(i.second);
    c[i.first] = f(i.second);
    d[i.first] = f(i.second-1);
  }

  for (int i = 0; i < n; i++) {
    cout << ret - c[a[i]] + d[a[i]] << endl;
  }
  return 0;
}