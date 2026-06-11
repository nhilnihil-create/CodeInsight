#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;
  int A,B;
  int outlet = 1;

  cin >> A >> B;
  
  while(outlet < B){
    --outlet;
    outlet += A;
    ans += 1;
  }

  cout << ans << endl;
  return 0;
}
