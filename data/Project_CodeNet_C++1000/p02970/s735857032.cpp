#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  
  int ans = 1;
  while ((d*2+1)*ans < n) ans++;
  cout << ans << endl;
}