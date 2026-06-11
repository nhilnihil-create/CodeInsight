#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)
int main() {
  int n, k, q, a;
  cin >> n >> k >> q;
  vector<int> v(n, 0);
  rep(i, q) {
    cin >> a;
    v[a-1]++;
  }
  rep(i, n) cout << ((k + v[i] - q > 0) ? "Yes" : "No") << endl;
}