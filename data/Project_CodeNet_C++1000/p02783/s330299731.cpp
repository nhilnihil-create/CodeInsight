#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,a;
  cin >> h >> a;
  int ans = 0;
  
  for (int i = 0;h > 0;i++){
    h -= a;
    ans++;
  }
  
  cout << ans << endl;
    
}