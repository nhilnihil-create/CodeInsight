#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef i64 int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define sz(a) i64((a).size())
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

class SegTree {
public:
	
  ////////////////////////////////////////////////////////

  // monoid
  using X = long long;
  X X_dot_X(const X &v1, const X &v2) {
    return v1 + v2;
  }
  const X X_unit = 0;
  
  ////////////////////////////////////////////////////////
  typedef size_t idx_type;
  
  vector<X> data;

  idx_type n;
	
  SegTree(idx_type n_) {
    n = 1;
    while(n <= size_t(n_)) {
      n *= 2;
    }
    data.resize(n * 2 - 1, X_unit);
  }
  ~SegTree() {}
  
  X query(idx_type a, idx_type b, idx_type k, idx_type l, idx_type r) {
    if(r <= a || b <= l) {
      return X_unit;
    }
		
    if(a <= l && r <= b) {
      return data[k];
    }
    else {
      X vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return X_dot_X(vl, vr);
    }
  }
  
  X query(idx_type a, idx_type b) {
    return query(a, b, 0, 0, n);
  }
	
  void update(idx_type i, X x) {
    i += n - 1;
    data[i] = x;
    while(i > 0) {
      i = (i - 1) / 2;
      data[i] = X_dot_X(data[i*2+1], data[i*2+2]);
    }
  }
};


int main(int argc, char *argv[]) {

  i64 N, Q, i;
  cin >> N >> Q;
  SegTree tree(N);
  REP(0, N, i) {
    i64 a;
    cin >> a;
    tree.update(i, a);
  }

  REP(0, Q, i) {
    i64 p, q, r;
    cin >> p >> q >> r;
    if(p == 0) {
      i64 cur = tree.query(q, q+1);
      tree.update(q, cur+r);
    }
    else {      
      cout << tree.query(q, r) << endl;
    }
  }

  return 0;
}
