#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
  int n;
  cin >> n;
  vector<int> ans(n + 1, 0);
  for (int i = 2; i < n + 1; i++) {
    int j;
    cin >> j;
    ans[j]++;
  }
  for (int i = 1; i < n + 1; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}