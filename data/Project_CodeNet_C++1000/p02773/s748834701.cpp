#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  map<string, ll> mp1;
  rep(i, n) {
    string s;
    cin >> s;
    mp1[s]++;
  }
  map<ll, vs> mp2;
  for(auto v : mp1) {
    string s = v.first;
    ll k = v.second;
    mp2[k].push_back(s);
  }
  vs s = (*mp2.rbegin()).second;
  sort(all(s));
  for(auto v : s) cout << v << '\n';
}