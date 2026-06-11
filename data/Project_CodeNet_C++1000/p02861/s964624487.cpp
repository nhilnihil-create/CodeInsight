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

class Permutation {
  ll *_array;
  ll _length;
  bool _finished;

 public:
  Permutation(ll *array, ll length) {
    _array = array;
    _length = length;
    _finished = false;
  }

  void next() {
    if (_finished) {
      return;
    }
    if (!next_permutation(_array, _array + _length)) {
      _finished = true;
    }
  }

  ll data(ll index) { return _array[index]; }

  void print() {
    for (ll i = 0; i < _length; i++) {
      cout << _array[i];
    }
    cout << endl;
  }

  bool finished() { return _finished; }
};

int main() {
  std::cout << std::fixed << std::setprecision(10);

  ll N;
  scanf("%lld", &N);

  vector<pair<ll, ll>> list;
  for (ll i = 0; i < N; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    list.emplace_back(make_pair(a, b));
  }

  vector<ll> v;
  for (ll i = 0; i < N; i++) {
    v.emplace_back(i);
  }

  ll count = 0;
  double sum = 0;

  auto perm = Permutation(v.data(), v.size());
  while (!perm.finished()) {
    // perm.print();
    double this_sum = 0;
    pll current;
    current.first = list[perm.data(0)].first;
    current.second = list[perm.data(0)].second;
    for (ll i = 1; i < N; i++) {
      ll next_index = perm.data(i);
      pll next = list[next_index];

      ll dx = (next.first - current.first);
      ll dy = (next.second - current.second);

      double plus = pow(dx * dx + dy * dy, 0.5);

      this_sum += plus;

      current = next;
    }
    // cout << "this_sum:" << this_sum << endl;
    sum += this_sum;

    count++;
    perm.next();
  }

  double ans = sum / count;
  cout << ans << endl;
}
