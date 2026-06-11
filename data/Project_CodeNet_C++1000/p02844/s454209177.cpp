#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

string str;
vll numbers;

class BitComb {
 private:
  ll _digits;
  ll _base;
  ll _data[512];
  ll _finished;
  ll _i;

 public:
  BitComb(ll digits, ll base) {
    _digits = digits;
    _base = base;
    _finished = false;
    _i = 0;
    fill_n(_data, 512, 0);
  }

  void next() {
    if (_finished) {
      return;
    }
    for (ll i = 0; i < _digits; i++) {
      if (_data[i] + 1 < _base) {
        _data[i] += 1;
        break;
      } else {
        _data[i] = 0;

        if (i == _digits - 1) {
          _finished = true;
          break;
        }
      }
    }
  }

  ll data(ll index) { return _data[index]; }

  void print() {
    for (ll i = _digits - 1; i >= 0; i--) {
      cout << _data[i];
    }
    cout << endl;
  }

  bool finished() { return _finished; }
};

ll N;

bool ok(ll v0, ll v1, ll v2) {
  ll index = 0;

  for (ll i = 0; i < N; i++) {
    ll v;
    if (index == 0) v = v0;
    if (index == 1) v = v1;
    if (index == 2) v = v2;
    if (numbers[i] == v) {
      index++;
      if (index >= 3) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  scanf("%lld", &N);
  cin >> str;

  for (ll i = 0; i < N; i++) {
    numbers.emplace_back(str[i] - '0');
  }

  ll ans = 0;
  auto bc = BitComb(3, 10);
  while (!bc.finished()) {
    // bc.print();
    if (ok(bc.data(0), bc.data(1), bc.data(2))) {
      ans++;
    }
    bc.next();
  }

  cout << ans << endl;
}
