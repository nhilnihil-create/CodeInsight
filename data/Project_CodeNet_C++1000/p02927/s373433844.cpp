#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int m, d, c = 0;
  cin >> m >> d;
  if (m < 4 || d < 22) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 4; i <= m; i++) {
    for (int j = 22; j <= d; j++) {
      if ((j / 10) < 2 || (j % 10) < 2) continue;
      if ((j / 10) * (j % 10) == i) {
        c++;
      }
    }
  }

  cout << c << endl;

  return 0;
}