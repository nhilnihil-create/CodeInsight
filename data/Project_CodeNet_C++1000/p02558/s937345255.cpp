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

class UnionFindTree {
public:
  UnionFindTree(i64 N) : trees(N, -1), height(N, 1), count(N, 1) {
  }

  void merge(i64 ia, i64 ib) {
    if(is_same_group(ia, ib)) {
      return;
    }

    if(height[ia] > height[ib]) {
      swap(ia, ib);
    }

    i64 rb = find_root(ib), ra = find_root(ia);
    count[rb] += count[ra];
    count[ra] = 0;

    while(trees[ia] != -1) {
      i64 next = trees[ia];
      trees[ia] = ib;
      ia = next;
    }
    trees[ia] = ib;
  }

  bool is_same_group(i64 ia, i64 ib) {
    return find_root(ia) == find_root(ib);
  }

  i64 find_root(i64 ia) {
    vi children;
    i64 i;
    while(trees[ia] != -1) {
      children.pb(ia);
      ia = trees[ia];
    }
    REP(0, sz(children), i) {
      trees[children[i]] = ia;
    }
    return ia;
  }

  vi trees;
  vi height;
  vi count;
};

int main(int argc, char *argv[]) {
  i64 N, Q, i;
  cin >> N >> Q;
  UnionFindTree tree(N);
  REP(0, Q, i) {
    i64 t, u, v;
    cin >> t >> u >> v;
    if(t == 0) {
      tree.merge(u, v);
    }
    else {
      cout << (tree.find_root(u) == tree.find_root(v) ? 1 : 0) << endl;
    }
  }

  return 0;
}
