#include <bits/stdc++.h>
using namespace std;
int mp[10][5];
int main() {
  while (true) {
    int h;
    cin >> h;
    if (h == 0)
      break;
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 5; j++)
        mp[i][j] = 0;
    for (int i = h - 1; i >= 0; i--)
      for (int j = 0; j < 5; j++)
        cin >> mp[i][j];
    bool found = true;
    int score = 0;
    while (found) {
      found = false;
      for (int i = 0; i < 10; i++) {
        int bg = 0;
        for (int j = 1; j < 5; j++) {
          if (mp[i][j] != mp[i][bg]) {
            if (j - bg >= 3 && mp[i][bg] != 0) {
              found = true;
              for (int k = bg; k < j; k++) {
                score += mp[i][k];
                mp[i][k] = 0;
              }
            }
            bg = j;
          }
        }
        if (bg <= 2 && mp[i][bg] != 0) {
          found = true;
          for (int k = bg; k < 5; k++) {
            score += mp[i][k];
            mp[i][k] = 0;
          }
        }
      }
      for (int j = 0; j < 5; j++) {
        int t[10], p = 0;
        for (int i = 0; i < 10; i++)
          t[i] = 0;
        for (int i = 0; i < 10; i++)
          if (mp[i][j] != 0)
            t[p++] = mp[i][j];
        for (int i = 0; i < 10; i++)
          mp[i][j] = t[i];
      }
    }
    cout << score << endl;
  }
}
