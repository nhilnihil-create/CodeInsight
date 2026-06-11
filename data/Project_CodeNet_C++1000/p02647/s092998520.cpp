#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(_, k) {
    vector<int> b(n+1);
    rep(i, n) {
      int x = a[i];
      b[max(0, i-x)]++;
      b[min(n, i+x+1)]--;
    }
    rep(i, n) b[i+1] += b[i];
    b.pop_back();
    if (a == b) break;
    a = b;
  }
  rep(i, n) cout << a[i] << " \n"[i == n-1];
}