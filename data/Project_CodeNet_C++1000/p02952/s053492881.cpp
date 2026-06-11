#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
#define all(x) (x).begin(), (x).end()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end());
const long long INF = 1LL << 60;
// map<int,int> mp;

bool solve(int n) {
  int k = to_string(n).size();
  if (k % 2 == 1) return true;
  return false;
}

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    if (solve(i) == true) ans++;
  }
  cout << ans << endl;
}