#include <bits/stdc++.h>
using namespace std;

int main() {
  int ar[2];
  cin >> ar[0] >> ar[1];
  int ans = 0;
  for(int i = 0; i < 2; i++){
    if(ar[i] == 1) ans += 300000;
    else if(ar[i] == 2) ans += 200000;
    else if(ar[i] == 3) ans += 100000;
  }
  if(ar[0] == 1 && ar[1] == 1) ans += 400000;
  cout << ans << endl;
  return 0;
}