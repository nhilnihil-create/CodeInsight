#include <bits/stdc++.h>
using namespace std;

int main() {
  long long H;
  long long X=1;
  long long ans =0;
  cin >> H;

 

  while(H != 0){
    ans += X;
    H /= 2;
    X *= 2;
  }
  cout << ans << endl;
  return 0;
}
