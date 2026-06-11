#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
const int inf = 100100100;


int main(){
  int n,m;
  cin >> n >> m;

  dsu d(n);
  rep(i,m) {
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    d.merge(a,b);
  }

  int ans = d.groups().size()-1;
  cout << ans << endl;
}
