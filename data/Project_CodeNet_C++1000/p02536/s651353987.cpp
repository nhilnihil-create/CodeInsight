#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

// ACL C
// https://atcoder.jp/contests/abl/tasks/abl_c

int main() {
  int n, m;
  cin >> n >> m;
  dsu uf(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.merge(a, b);
  }

  // int cnt = 0;
  // rep(i, n) if(uf.leader(i) == i) cnt++;
  int cnt = uf.groups().size();
  cout << cnt - 1;
}
