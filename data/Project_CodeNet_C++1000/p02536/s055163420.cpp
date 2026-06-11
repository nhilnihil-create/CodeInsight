#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main(){

  int n, m;
  cin >> n >> m;

  atcoder::dsu d(n);
  int res = n-1;

  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    --a; --b;
    if(!d.same(a, b)){
      --res;
      d.merge(a, b);
    }
  }
  cout << res << '\n';

  return 0;
}
