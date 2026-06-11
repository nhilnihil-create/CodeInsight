#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  int maxa=0, ai=0, sa=0;
  rep(i,n) {
    cin >> a[i];
    if (maxa <= a[i]) {
      sa = maxa;
      maxa = a[i];
      ai = i;
    } else if (sa <= a[i]) sa = a[i];
  }
  rep(i,n) {
    if (i != ai) cout << maxa << endl;
    else cout << sa << endl;
  }
  return 0;
}