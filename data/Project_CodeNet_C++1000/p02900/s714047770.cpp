#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

vector<ll> prime_factor(ll a) {
  vector<ll> ret;
  for (ll i = 2; i*i <= a; i++) {
    if (a % i == 0) ret.push_back(i);
    while (a % i == 0) a /= i;
  }
  if (a != 1) ret.push_back(a);
  return ret;
}

int main() {
  ll A, B;
  cin >> A >> B;
  ll x = gcd(A, B);
  vector<ll> ans = prime_factor(x);
  ans.push_back(1);

  cout << ans.size() << endl;
  return 0;
}
