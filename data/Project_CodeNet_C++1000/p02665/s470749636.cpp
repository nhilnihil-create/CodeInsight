#include <bits/stdc++.h>
#define dbg() cerr <<
#define name(x) (#x) << ": " << (x) << ' ' <<

using namespace std;

void NO() {
  cout << "-1\n";
  exit(0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  vector<int> leaves(n + 1);
  for (int &x : leaves) {
    cin >> x;
  }

  if (n == 0) {
    cout << (leaves[0] == 1 ? "1" : "-1") << endl;
    return 0;
  }

  if (leaves[0] != 0) NO(); 
  
  vector<int64_t> suff(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    suff[i] = suff[i + 1] + leaves[i + 1];
  }

  vector<int64_t> internal(n + 1);
  internal[0] = 1;
  for (int d = 1; d <= n; ++d) {
    internal[d] = min(2 * internal[d - 1] - leaves[d], suff[d]);
    if (internal[d] < 0) NO();
  }

  int64_t ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans += internal[i] + leaves[i];
  }

  cout << ans << endl;
}
