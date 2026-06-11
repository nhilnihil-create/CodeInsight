#include <bits/stdc++.h>
#include <atcoder/dsu>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using namespace atcoder;

signed main() {
  int n,m;
  cin >> n >> m;

  dsu Tree(n);
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    a--,b--;
    Tree.merge(a,b);
  }

  set<int> st;
  for (int i = 0; i < n; i++) {
    st.insert(Tree.leader(i));
  }
  cout << st.size() - 1 << endl;

}


