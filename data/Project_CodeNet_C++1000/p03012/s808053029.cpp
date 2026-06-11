#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n, sa = 0, sb = 0, m;
  cin >> n;
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
    sb += v[i];
  }
  m = sb;
  rep(i, n-1) {
    sa += v[i];
    sb -= v[i];
    m = min(m, abs(sa-sb));
  }
  cout << m << endl;
}
