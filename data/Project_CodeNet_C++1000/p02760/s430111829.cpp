#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define pi acos(-1)


int g[9];
bool hp() {
  if (g[0]==-1&&g[1]==-1&&g[2]==-1) return true;
  if (g[3]==-1&&g[4]==-1&&g[5]==-1) return true;
  if (g[6]==-1&&g[7]==-1&&g[8]==-1) return true;
  if (g[0]==-1&&g[3]==-1&&g[6]==-1) return true;
  if (g[1]==-1&&g[4]==-1&&g[7]==-1) return true;
  if (g[2]==-1&&g[5]==-1&&g[8]==-1) return true;
  if (g[0]==-1&&g[4]==-1&&g[8]==-1) return true;
  if (g[2]==-1&&g[4]==-1&&g[6]==-1) return true;
  return false;
}
int main() {
  for (int i = 0; i <9; i++) {
      cin >> g[i];
  }

  int n; cin >> n;

  for (int i =0 ; i < n; i++) {
    int m; cin >> m;
    for (int j =0 ; j < 9; j++) {
      if (g[j] == m) {
        g[j] = -1;
        if (hp()) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}

