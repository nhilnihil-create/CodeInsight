//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int R = n - 1;
  int ans = 0;
  bool done = false;
  for (int L = 0; L < n; L++) {
    if (s[L] == 'W') {
      while (s[R] == 'W') {
        --R;
        if (R < L) {
          done = true;
          break;
        }
      }
      if (done) {
        break;
      }
      ++ans;
      swap(s[L], s[R]);
    }
  }
  cout << ans << '\n';
  return 0;
}
