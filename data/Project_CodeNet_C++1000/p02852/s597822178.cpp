#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,M;
  cin >> N >> M;
  string S;
  cin >> S;
  vector<int> ans;
  
  int now = N;
  while (0 == 0) {
    int t = -1;
    for (int i = max(0,now - M); i < now; i++) {
      if (S[i] == '0') {
        t = now - i;
        break;
      }
    }
    if (t == -1) {
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(t);
    now -= t;
    if (now == 0) {
      break;
    }
  }

  for (int i = (int)ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  return 0;
}