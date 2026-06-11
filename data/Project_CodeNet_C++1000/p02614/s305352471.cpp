#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int h,w,k;
bool isApplied(vector<vector<char>> garden) {
  int cnt = 0;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (garden[i][j] == '#') {
        cnt++;
      }
    }
  }
  if (cnt == k) {
    return true;
  }
  return false;
}

int main() {
  cin >> h>>w>>k;
  vector<vector<char>> garden;

  for (int i=0; i<h; i++) {
    vector<char> V;
    for (int j=0; j<w; j++) {
      char a;
      cin >> a;
      V.push_back(a);
    }
    garden.push_back(V);
  }

  int ans = 0;

  for (int i=0; i < (1 << h); i++) {
    for (int j=0; j < (1 << w); j++) {
      vector<vector<char>> garden2 = garden;
      for (int y=0; y < h; y++) {
        if (i & (1<<y)) {
          // yoko ichiretu umeru
          for (int yoko=0; yoko<w;yoko++){
            garden2[y][yoko] = '.';
          }
        }
      }
      for (int x=0; x < w; x++) {
        if (j & (1 << x)) {
          for (int tate=0; tate<h;tate++) {
            garden2[tate][x] = '.';
          }
        }
      }
      if (isApplied(garden2)) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}
