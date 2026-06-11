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

  vector<ll> vec() {
    vector<ll> r;

    for (ll i = 0; i < _length; i++) {
      r.emplace_back(_array[i]);
    }

    return r;
  }

  void print() {
    for (ll i = 0; i < _length; i++) {
      cout << _array[i];
    }
    cout << endl;
  }

  bool finished() { return _finished; }
};

int main() {
  ll N;
  scanf("%lld", &N);

  vector<ll> v;
  for (ll i = 1; i <= N; i++) {
    v.emplace_back(i);
  }

  vector<ll> p;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    p.emplace_back(v);
  }

  vector<ll> q;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    q.emplace_back(v);
  }

  ll p_index = -1;
  ll q_index = -1;

  ll count = 1;
  auto perm = Permutation(v.data(), v.size());
  while (!perm.finished()) {
    // perm.print();

    if (perm.vec() == p) {
      p_index = count;
    }
    if (perm.vec() == q) {
      q_index = count;
    }

    perm.next();

    count += 1;
  }

  // cout << "p_index:" << p_index << endl;
  // cout << "q_index:" << q_index << endl;

  cout << abs(p_index - q_index) << endl;
}
