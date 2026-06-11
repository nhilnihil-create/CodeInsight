#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int M, D, ans = 0;
  cin >> M >> D;
  for (int i=1; i<=M; i++) {
    for (int j=1; j<=D; j++) {
      int d1 = j%10;
      int d10 = j/10;
      if (d1>=2&&d10>=2&&d1*d10==i) ans++;
    }
  }
  cout << ans << endl;
}