//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

const int N = 10;

string s[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int bh = 0; bh < (1 << h); bh++) {
    for (int bw = 0; bw < (1 << w); bw++) {
      int cnt = 0;
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          if (s[i][j] == '#' && (bh & (1 << i)) && (bw & (1 << j))) {
            ++cnt;
          }
        }
      }
      ans += (cnt == k);
    }
  }
  cout << ans << '\n';
  return 0;
}
