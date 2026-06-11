#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, C;
  int ans;
  cin >> A >> B >> C;
  ans = C - (A - B);
  if(ans > 0) cout << ans << "\n";
  else cout << 0 << "\n";
  return 0;
}
