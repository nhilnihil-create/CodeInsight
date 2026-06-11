#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n, 0);
  ll ans = 1;
  ll zero = 3;
  for(int i = 0; i < n; i++) {
    b[a[i]]++;
    if(a[i] == 0) {
      ans *= zero;
      zero--;
    } else {
      ans *= b[a[i] - 1];
      b[a[i] - 1]--;
    }
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}