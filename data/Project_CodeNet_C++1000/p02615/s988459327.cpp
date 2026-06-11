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
  int n;
  cin >> n;
  vector<ll> a;
  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  // for (int i = 0; i < n - 1; i++) {
  //   if (a.at(i) == a.at(i + 1)) cout << a.at(i) << endl;
  // }

  ll ans = 0;
  ll currNum = a.front();
  int cnt_currNum = 0;
  int cnt_prevNums = 0;
  int cnt_ans = 0;
  for (int i = 0; i < n; i++) {
    if (a.at(i) != currNum || i == n - 1) {
      int times;
      if (cnt_currNum <= cnt_prevNums)
        times = 2 * cnt_currNum;
      else
        times = 2 * cnt_prevNums + (cnt_currNum - cnt_prevNums) +
                (cnt_currNum - cnt_prevNums);
      if (ans == 0) times--;
      for (int j = 0; j < times; j++) {
        ans += currNum;
        cnt_ans++;
        if (cnt_ans == n - 1) break;
      }
      if (cnt_ans == n - 1) break;

      currNum = a.at(i);
      cnt_currNum = 0;
      cnt_prevNums = i;
    }

    cnt_currNum++;
  }

  cout << ans << endl;
}