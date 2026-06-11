#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
  int n, m;
  cin >> n >> m;
  dsu uf(n);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    int a, b;
    cin >> a >> b;
    if (t) {
      cout << uf.same(a,b) << endl;
    } else {
      uf.merge(a,b);
    }
  }
}
