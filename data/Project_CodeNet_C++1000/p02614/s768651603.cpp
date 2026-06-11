#include <iostream>
#include <vector>
using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  int ans = 0;
  for (int i = 0; i < h; i++) cin >> s[i];
  for (int i = 0; i < (1<<h); i++) {
    for (int j = 0; j < (1<<w); j++) {
      int count = 0;
      for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
          if (i>>x & 1) continue;
          if (j>>y & 1) continue;
          if (s[x][y] == '#') count++;
        }
      }
      if (count == k) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}