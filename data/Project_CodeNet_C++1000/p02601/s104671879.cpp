#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, k;
  cin >> a >> b >> c >> k;

  while (a >= b && k > 0){
    b *= 2;
    k -= 1;
  }
  while (b >= c && k > 0){
    c *= 2;
    k -= 1;
  }

  cout << ((b > a && c > b) ? "Yes" : "No") << endl;
  
  return 0;
}
