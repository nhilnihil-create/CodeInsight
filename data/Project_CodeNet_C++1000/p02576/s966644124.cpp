#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N,X,T;
  cin >> N >> X >> T;
  int ans = ((N - 1) / X + 1)*T;
  cout << ans << endl;
  return 0;
}