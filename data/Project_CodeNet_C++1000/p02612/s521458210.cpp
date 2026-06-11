/**
 * author:  virenkathiriya96
 * created: 2020.08.31 14:34:20 
**/

#include<bits/stdc++.h>

using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int c;
  cin >> c;
  int ans = (c % 1000 == 0) ? 0 : 1000 - (c % 1000);
  cout << ans << "\n";
  return 0;
}