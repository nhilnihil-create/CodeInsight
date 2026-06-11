#include <bits/stdc++.h>
using namespace std;

int main() {
  long long h;
  cin >> h;
  int n = 0;
  
  for (int i = 0;h > 1;i++){
    h /= 2;
    n++;
  }
  
  long long ans = pow(2,n+1) - 1;

  cout << ans << endl;
}
