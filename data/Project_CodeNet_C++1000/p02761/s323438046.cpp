#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define pi acos(-1)


int main() {
  int n,m; cin >>n>>m;
  if (n==1&&m==0) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> res(n, -1);
  for (int i = 0; i < m; i++) {
    int s,c; cin >> s >> c;
    if ((n!=1&&s==1&&c==0) || (res[s-1] != -1 && res[s-1] != c)) {
      cout << -1 << endl;
      return 0;
    }
    res[s-1] = c;
  }
  if (res[0] == -1 || res[0] == 0) res[0] = (n==1?0:1);
  int ans = 0;
  for (auto i : res) {
    ans = ans*10 + (i<0?0:i);
  }
  cout << ans << endl;
  return 0;
}
