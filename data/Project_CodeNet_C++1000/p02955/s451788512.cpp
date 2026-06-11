#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> divisor(ll n) { 
  vector<ll> ret;
  for (ll i = 1; (ll)i*i <= n; ++i) { 
    if (n % i == 0) {
      ret.push_back(i);
      if (i*i != n) { ret.push_back(n/i); }
    }
  }
  sort(ret.begin(), ret.end(), greater<ll>());
  return ret;
};


int main() {
  ll n, k; cin >> n >> k;
  vector<ll> la(n);
  ll s = 0;
  for (ll &a: la) {
    cin >> a;
    s += a;
  }
  vector<ll> divs = divisor(s);
  for (ll d : divs) {
    // cerr << d << endl;
    auto check = [&](ll x){
      vector<ll> lr;
      for (ll a : la) { 
        lr.push_back(a%d);
      }
      sort(lr.begin(), lr.end());
      vector<ll> s1(n+1), s2(n+1);
      for (ll i = 0; i < n; ++i) {
        s1[i+1] += s1[i] + lr[i];
        s2[n-i-1] += s2[n-i] + d-lr[n-i-1];
      }
      for (ll i = 0; i <= n; ++i) {
        // cerr << i << " " << s1[i] << " " << s2[i] << endl;
        if (max(s1[i], s2[i]) <= k) return true;
      }
      return false;
    };
    if (check(d)) { 
      cout << d << endl;
      return 0;
    }
  }

}

