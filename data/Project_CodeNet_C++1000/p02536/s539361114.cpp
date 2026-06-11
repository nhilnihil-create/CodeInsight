#include <bits/stdc++.h>
using namespace std;

class ufds_t {
public:
  using ints_t = vector<int>;

  ufds_t(int n) {
    _parents.resize(n+1);
    iota(_parents.begin(), _parents.end(), 0);
    _sizes.assign(n+1, 1);
    _ranks.assign(n+1, 0);
    _disjoint_sets_nb = n;
    _n = n;
  }

  int get_parent(int u) {
    if(_parents[u] == u) {
      return u;
    } else {
      _parents[u] = get_parent(_parents[u]);
      return _parents[u];
    }
  }

  void add(int u, int v) {
    int p_u = get_parent(u);
    int p_v = get_parent(v);

    if(p_u == p_v) {
      return;
    }

    if(_ranks[p_u] > _ranks[p_v]) {
      _parents[p_v] = _parents[p_u];
      _sizes[p_u] += _sizes[p_v];
    } else {
      _parents[p_u] = _parents[p_v];
      _sizes[p_v] += _sizes[p_u];
    }

    if(_ranks[p_u] == _ranks[p_v]) {
      ++_ranks[p_v];
    }
    --_disjoint_sets_nb;
  }

  int disjoint_sets_nb() {
    return _disjoint_sets_nb;
  }

  void trace() {
    cout << "i: ";
    for(int i = 1; i <= _n; ++i) {
      cout << setw(2) << i << " ";
    }
    cout << "\n";
    cout << "p: ";
    for(int i = 1; i <= _n; ++i) {
      cout << setw(2) << _parents[i] << " ";
    }
    cout << "\n";
    cout << "r: ";
    for(int i = 1; i <= _n; ++i) {
      cout << setw(2) << _ranks[i] << " ";
    }
    cout << "\n";
    cout << "s: ";
    for(int i = 1; i <= _n; ++i) {
      cout << setw(2) << _sizes[i] << " ";
    }
    cout << "\n";
  }

protected:
  ints_t _parents, _sizes, _ranks;
  int _disjoint_sets_nb;
  int _n;
};

int main() {
  int n, m;
  cin >> n >> m;

  ufds_t ufds(n);
  while(m--) {
    int u, v;
    cin >> u >> v;

    ufds.add(u, v);
  }

  //ufds.trace();

  int disjoint_sets_nb = ufds.disjoint_sets_nb();
  if(disjoint_sets_nb > 0) {
    cout << disjoint_sets_nb - 1 << "\n";
  } else {
    cout << "\n";
  }

  return 0;
}