////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
namespace my {
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
ll lcm(ll a, ll b) { return a * b / my::gcd(a, b); }  // O( log(a) )
bool isPrime(ll n) {                                  // O( sqrt(n) )
  bool flag = true;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) flag = false;
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
////////////////////////

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a, b;
  vector<ll> sa, sb;
  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
    if (i == 0)
      sa.push_back(tmp);
    else
      sa.push_back(sa.back() + tmp);
  }
  for (int i = 0; i < m; i++) {
    ll tmp;
    cin >> tmp;
    b.push_back(tmp);
    if (i == 0)
      sb.push_back(tmp);
    else
      sb.push_back(sb.back() + tmp);
  }

  int ans = 0;
  int iOver = distance(sa.begin(), upper_bound(sa.begin(), sa.end(), k));
  for (int i = -1; i < iOver; i++) {
    int tmp;
    ll time_a;
    if (i == -1) {
      time_a = 0;
      tmp = 0;
    } else {
      time_a = sa.at(i);
      tmp = i + 1;
    }
    tmp += distance(sb.begin(), upper_bound(sb.begin(), sb.end(), k - time_a));
    ans = max(ans, tmp);
  }

  cout << ans << endl;
}