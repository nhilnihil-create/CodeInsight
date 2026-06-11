#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a, b, c;
  cin >> a >> b >> c;
  
  int n = max({a, b, c});
  int ans = a + b + c - n;
  cout << ans << endl;

}