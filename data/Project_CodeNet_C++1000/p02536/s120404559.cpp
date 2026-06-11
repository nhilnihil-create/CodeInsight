#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < n; i++)

int main(){
  int n,m;
  cin >> n >> m;
  dsu d(n);
  int i;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a,--b;
    d.merge(a, b);
  }
  cout << d.groups().size() - 1 << endl;
}