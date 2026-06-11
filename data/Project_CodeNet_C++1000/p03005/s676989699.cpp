#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  if(k == 1) n = k;
  int ans = n - k;
  cout << ans << endl;
  return 0;
}