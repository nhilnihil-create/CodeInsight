#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;


int main() {
  ll n;
  cin >> n;
  vector<ll> A;
  for  (ll i = 2; i*i <= n; ++i) {
    if (n%i == 0) {
      A.push_back(i);
      if (i*i < n) {
        A.push_back(n/i);
      }
    }
  }

  auto f = [&](ll a, ll b) {
    while(a%b == 0) a /= b;
    if (a%b == 1) return 1;
    else return 0;
  };

  int ans = 1;
  for (ll x: A) {
    ans += f(n, x);
  }
  for  (ll i = 1; i*i <= n-1; ++i) {
    if ((n-1)%i == 0) {
      ++ans;
      if (i!=1 && i*i!=(n-1)) ++ans;
      if (i==1 && i*i==(n-1)) --ans;
    }
  }
  cout << ans << endl;
  return 0;
}