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
  set<int> A;
  rep(i, N) {
    int a;
    cin >> a;
    A.insert(a);
  }
  bool bl = (sz(A) == N);
  if (bl) puts("YES");
  else puts("NO");
  return 0;
}