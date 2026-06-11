#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> var(5);
  
  for(int i = 0; i < 5; i++) cin >> var[i];
  
  int ans = 0;
  for(int i = 0; i < 5; i++) {
    ans++;
    if(var[i] == 0) break;
  }
  cout << ans << endl;
  return 0;
}
