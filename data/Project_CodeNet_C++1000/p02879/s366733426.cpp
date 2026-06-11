/**
 *  author: Behradm
 *  Created: 2020.08.02 15:47:05
 *  In The Name Of God
**/
#include <bits/stdc++.h>

using namespace std;

int main() {   
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << (a >= 1 && a <= 9 && b >= 1 && b <= 9 ? a * b : -1) << '\n';
  return 0;
}
