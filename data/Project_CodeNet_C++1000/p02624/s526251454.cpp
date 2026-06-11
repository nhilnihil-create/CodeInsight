////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

namespace my {
template <typename T>
void input_vec(vector<T> &a, ll n) {
  if (!a.empty()) {
    cout << "wrong argument in input_vec" << endl;
    exit(1);
  }
  for (ll i = 0; i < n; i++) {
    T tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
}
template <typename T>
void input_set(set<T> &a, ll n) {
  if (!a.empty()) {
    cout << "wrong argument in input_set" << endl;
    exit(1);
  }
  for (ll i = 0; i < n; i++) {
    T tmp;
    cin >> tmp;
    a.insert(tmp);
  }
}

char itoc(int i) { return i + '0'; }
int ctoi(char c) { return c - '0'; }

ll gcd(ll a, ll b) {  // O( log(a) )
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
ll lcm(ll a, ll b) { return a * (b / my::gcd(a, b)); }  // O( log(a) )

bool isPrime(ll n) {  // O( sqrt(n) )
  bool flag = true;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}

vector<pair<ll, ll>> primeFac(ll n) {  // O( sqrt(n) )
  vector<pair<ll, ll>> ret;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    ll exp = 0;
    while (n % i == 0) {
      n /= i;
      exp++;
    }
    ret.push_back(make_pair(i, exp));
  }
  if (n != 1) ret.push_back(make_pair(n, 1));
  return ret;
}
}  // namespace my
////////////////////////////////////////////////

int main() {
  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll shokou = i;
    ll makkou = (n / i) * i;
    ll kousa = i;
    ll kousuu = (makkou - shokou) / kousa + 1;
    ans += (kousuu * (shokou + makkou)) / 2;
    // cout << ans << endl;
  }

  cout << ans << endl;
}