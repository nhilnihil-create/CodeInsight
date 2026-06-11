#include <bits/stdc++.h>
using namespace std;

int main() {
  long L,R; cin >> L >> R;
  int modL = L % 2019;
  int modR = R % 2019;
  long ans;
  if (R - L >= 2019) {
    ans = 0;
  } else { 
    ans = 2019;
    for (long i =L; i<=R; i++) {
      for (long j =i+1; j<=R; j++) {
        long modIJ = i * j % 2019;
        ans = min(modIJ,ans);
      }
    }
  }
  cout << ans << endl;
}