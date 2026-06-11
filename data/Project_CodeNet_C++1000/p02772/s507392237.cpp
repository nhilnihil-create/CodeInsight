#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  bool bl = true;
  rep(i, N) {
    if (A[i]%2 == 0 && (A[i]%3 != 0 && A[i]%5 != 0)) {
      bl = false;
    }
  }
  if (bl) puts("APPROVED");
  else puts("DENIED");
  return 0;
}