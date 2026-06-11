#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k, s; cin >> n >> k >> s;
  vector<int> a(n,s/2+10);
  rep(i, k) {
    a[i] = s;
  }
  rep(i,n) {
    cout << a[i];
    if (i!=n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}