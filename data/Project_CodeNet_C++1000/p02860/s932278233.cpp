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
  string s;
  cin >> n >> s;
  bool ans = true;
  if(n % 2)
    ans = false;
  else {
    string s1 = s.substr(0, n / 2);
    string s2 = s.substr(n / 2, n / 2);
    if(s1 != s2) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}