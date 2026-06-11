#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;


int main() {
  ll n;
  cin >> n;
  vector<ll> a(n); rep(i,n) cin >> a[i];

  ll sum = 0;
  rep(i,n) sum += a[i];
  ll even_sum = 0;
  for(ll i = 1; i < n; i += 2 ) {
    even_sum += a[i];
  }

  ll x_1 = sum - 2*even_sum;
  cout << x_1;
  ll x_i = x_1;
  rep(i,n) {
    if( i == n-1 ) continue;
    x_i = 2*a[i] - x_i;
    cout << ' ' << x_i;
  } 
  cout << endl;
  return 0;
}
