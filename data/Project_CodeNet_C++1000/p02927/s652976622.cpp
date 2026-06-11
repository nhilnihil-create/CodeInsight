#include <bits/stdc++.h>
using namespace std;
int main () {
  int M, D;
  cin >> M >> D;
  int ans = 0;
  for(int i = 22; i <= D; i++){
    if(i % 10 == 1)continue;
    if(4 <= (i / 10) * (i % 10) && M >= (i / 10) * (i % 10)){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
