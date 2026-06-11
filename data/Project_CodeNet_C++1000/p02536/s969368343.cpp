#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); i++)
int main() {
  int n, m;
  cin >> n >> m;
  dsu uf(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    uf.merge(a-1,b-1);
  }
  map<int,int> mp;
  int ans = 0;
  rep(i,n) {
    if (mp[uf.leader(i)]) continue;
    mp[uf.leader(i)]++;
    ans++;
  }
  ans--;
  cout << ans << endl;
}
