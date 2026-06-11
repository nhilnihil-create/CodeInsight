#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int p;
  int ans = 0;
  int num = 100000000;
  for(int i=0; i<n; i++) {
    cin >> p;
    if(p<=num) ans++;
    num = min(num, p);
  }
  cout << ans << endl;
  return 0;
}