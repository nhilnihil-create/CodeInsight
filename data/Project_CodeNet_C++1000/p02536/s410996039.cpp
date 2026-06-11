#include <bits/stdc++.h>
using namespace std;
#define int long long

struct UnionFind {
    vector<int> Parent;
    vector<int> Size;

    UnionFind(int N) : Parent(N), Size(N,1){
        for(int i = 0; i < N; i++) Parent[i] = i;
    }

    int root(int A) {
        if (Parent[A] == A) return A;
        return Parent[A] = root(Parent[A]);
    }

    bool merge(int A, int B) {
        A = root(A);
        B = root(B);
        if (A == B) return false;

        if (Size[A] < Size[B]) swap(A, B);

        Size[A] += Size[B];
        Parent[B] = A;
        return true;
    }

    bool issame(int A, int B) {
        return root(A) == root(B);
    }

    int findsize(int A) {
        return Size[root(A)];
    }
};

signed main() {
  int n,m;
  cin >> n >> m;

  UnionFind Tree(n);
  for (int i = 0; i < m; i++) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    Tree.merge(a,b);
  }

  set<int> st;
  for (int i = 0; i < n; i++) {
    st.insert(Tree.root(i));
  }

  int ans = st.size();
  cout << ans - 1 << '\n';
}


