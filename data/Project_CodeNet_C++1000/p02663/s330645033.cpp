#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int ans = (c*60+d) - (a*60+b) - e;
  cout << ans << endl;
}