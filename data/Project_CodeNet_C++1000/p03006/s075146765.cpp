#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

ll gcd(ll a, ll b) {
  ll tmp;
  if ( b > a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a % b !=0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main(void) {
  ll n;
  vector<pair<ll, ll>> v;
  map<pair<ll, ll>, ll> m;
  cin>>n;
  for(ll i=0; i<n; i++) {
    ll x, y;
    cin>>x>>y;
    v.push_back(make_pair(x, y));
  }

  for(ll i=0; i<n; i++) {
    for(ll j=i+1; j<n; j++) {
      m[make_pair(v[i].first-v[j].first, v[i].second-v[j].second)]++;
      m[make_pair(v[j].first-v[i].first, v[j].second-v[i].second)]++;
    }
  }
  ll ans=0;
  for(auto &p: m) {
    ans = max(ans, p.second);
  }
  std::cout << n-ans << std::endl;
  return 0;
}

