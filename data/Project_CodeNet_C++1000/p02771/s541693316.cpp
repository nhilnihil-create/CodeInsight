#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> A(3);
  rep(i, 3) cin >> A[i];
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  bool bl = (sz(A) == 2);
  if (bl) puts("Yes");
  else puts("No");
  return 0;
}