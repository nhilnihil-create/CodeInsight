#include<bits/stdc++.h>
using namespace std; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  string s;
  cin >> s;
  int ans = 0;
  int cnt = 0;
  for (int i = 0 ; i < 3; i++) {
    if (s[i] == 'R') cnt++;
    else cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
}