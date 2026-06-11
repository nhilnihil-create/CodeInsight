#include <iostream>
#include <string>
using namespace std;


int main() {
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for (int i = 1; i < n; ++i) { 
    int cnt = 0;
    int best = 0;
    for (int j = 0; j < n-i; ++j) { 
      if (s[j] != s[j+i]) {
        best = max(best, cnt);
        cnt = 0;
        continue;
      }
      ++cnt;
    }
    best = max(best, cnt);
    best = min(best, i);
    ans = max(ans, best);
  }
  cout << ans << endl;
}
