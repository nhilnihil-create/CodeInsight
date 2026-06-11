#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  int x = n;
  bool flag = (n%2 == 0);
  for (int i = 1; i <= m; ++i) {
    if (flag && x-i <= n/2) {
      --x;
      flag = false;
    }
    cout << i << " " << x-- << endl;
  }
}