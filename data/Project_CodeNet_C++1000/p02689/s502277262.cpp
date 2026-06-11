#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)n; i++)
const int INF = 1001001001;

int main() {
  int n,m;
  cin >> n >> m;
  std::vector<int> h(n);
  std::vector<bool> ok(n,true);
  for (int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  for (int i = 0; i < m; i++) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    if (h.at(a) <= h.at(b)) ok.at(a) = false;
    if (h.at(b) <= h.at(a)) ok.at(b) = false;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) if (ok.at(i)) ans++;
  cout << ans << endl;
  return 0;
}
