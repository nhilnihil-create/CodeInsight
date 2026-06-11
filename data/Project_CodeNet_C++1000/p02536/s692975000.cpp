#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Union-Find
class DisjointSet {
public:
  vector<int> p, rank, size;
  int group_num;
  DisjointSet(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    size.assign(n, 0);
    group_num = n;
    for (int i = 0; i < n; i++) {
      make_set(i);
    }
  }
 
  void make_set(int x) {
    p[x] = x;
    rank[x] = 0;
    size[x] = 1;
  }
 
  bool same(int x, int y) {
    return find_set(x) == find_set(y);;
  }
 
  int find_set(int x) {
    if (x != p[x]) {
      p[x] = find_set(p[x]);
    }
    return p[x];
  }
 
  int union_size(int x) {
    if (x != p[x]) {
      size[x] = union_size(find_set(x));
    }
    return size[x];
  }
 
  void link(int x, int y) {
    if(rank[x]  > rank[y]) {
      p[y] = x;
      size[x] = size[x] + size[y];
    }else if(rank[x] < rank[y]){
      p[x] = y;
      size[y] = size[x] + size[y];
    }else if(x != y) {
      p[y] = x;
      rank[x]++;
      size[x] = size[x] + size[y];
    }
  }
 
  void unite(int x, int y) {
    if (find_set(x) != find_set(y)) group_num--;
    link(find_set(x), find_set(y));
  }
};


int main() {
    int N, M;
    cin >> N >> M;
    int A[M], B[M];
    DisjointSet ds(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        ds.unite(A[i], B[i]);
    }
    cout << ds.group_num - 1 << "\n";
    return 0;
}