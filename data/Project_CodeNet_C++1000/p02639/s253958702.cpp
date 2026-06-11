/**
 *    author:  math2do
 *    created: 26.08.2020 15:09:26
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int v;
    cin >> v;
    if (v == 0) {
      ans = i + 1;
    } 
  } 
  cout << ans << endl;
  return 0;
}
