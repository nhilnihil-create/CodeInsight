#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int M,D;

int main() {
  cin>>M>>D;
  int ans = 0;

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= D; j++) {
      if (j < 20) continue;
      if (j%10 < 2) continue;
      if ((j/10)*(j%10) == i) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
