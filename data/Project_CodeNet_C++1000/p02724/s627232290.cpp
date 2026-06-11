#include <bits/stdc++.h>
using namespace std;
  
int main () {
  int X;
  cin >> X;
  int ans = 1000 * (X / 500) + 5 * ((X % 500) / 5);
  cout << ans << endl;
}