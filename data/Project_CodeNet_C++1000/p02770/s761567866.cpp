#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <map>
#include <functional>
#include <set>
using namespace std;
#define ll long long int
#define rep(i,k,n) for(int i = k; n > i; i++)
#define REP(i,n) rep(i,0,n)

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) { //ｘの入ってる集合と yの入ってる集合を併合
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { //xとyが同じ集合に入っているかどうかを判定
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	bool isroot(int x) {
		return data[x] < 0;
	}
	int size(int x) {
		return -data[root(x)];
	}
};

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }


  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};
int main(){
    int k,q;
    cin >> k >> q;

    vector<int> d(k);
    REP(i,k){
        cin >> d[i];
    }

    REP(i,q){
        int n,x,m, cou = 0;
        cin >> n >> x >> m;
        vector<int> buf(d);
        ll sum = 0;
        REP(j,k) {
            sum += d[j] % m;
            cou += d[j] % m == 0;
        }
        cou = cou * ((n-1)/k);
        sum = sum * ((n-1)/k) + x;
        REP(j, (n-1)%k){
            sum += d[j] % m;
            cou += d[j] % m == 0;
        }
        cou += sum/m - x/m;

        cout << n-1 - cou << endl;
    }

    return 0;
} 