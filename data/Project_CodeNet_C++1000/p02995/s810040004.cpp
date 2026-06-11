#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt(ll i, ll j, ll k) {
  return k - k/i - k/j + k/lcm(i,j);
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << cnt(c,d,b) - cnt(c,d,a-1) << endl;
}