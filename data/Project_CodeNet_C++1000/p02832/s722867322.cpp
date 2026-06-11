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
  int ans = 0;
  bool flag = true;
  int cur = 1;
  int index = 0;
  while (index < N) {
    if (A[index] == cur) {
      cur++; index++;
    } else {
      ans++; // レンガを砕く
      index++;
    }
  }
  if (cur == 1) ans = -1;
  cout << ans << '\n';
  return 0;
}