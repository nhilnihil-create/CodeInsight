/**
 *    AUTHOR:    crypter472                  
 *   CREATED:   12.09.2020 01:58:19  
**/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int d, t, s;
  cin >> d >> t >> s;
  cout << ((d + s - 1) / s <= t ? "Yes" : "No") << '\n';
  return 0;
}