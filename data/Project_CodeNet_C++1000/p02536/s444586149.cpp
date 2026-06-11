#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  dsu d(N);
  rep(i, M){
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    d.merge(a, b);
  }

  cout << d.groups().size() - 1 << endl;
  return 0;
}
