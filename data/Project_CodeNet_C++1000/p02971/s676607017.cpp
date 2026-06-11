#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,0,n) cin >> a[i];
  vector<int> b = a;
  sort(b.rbegin(), b.rend());
  int f = b[0], s = b[1];
  rep(i,0,n) {
    if (a[i] != f) cout << f << endl;
    else cout << s << endl;
  }
  return 0;
}
