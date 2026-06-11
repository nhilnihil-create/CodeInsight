#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a, b;
  cin >> a >> b;
  
  //2019=3*673 672*671/2=225456
  if(a%673==0 || a%673+b-a>=673) {
    if(b-a>=2) cout << 0 << endl;
    else cout << a*b%2019 << endl;
  }
  else {
    int64_t ans = 2020;
    for(int64_t i=a; i<=b-1; i++) {
      for(int64_t j=i+1; j<=b; j++) {
        ans = min(ans, i*j%2019);
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}