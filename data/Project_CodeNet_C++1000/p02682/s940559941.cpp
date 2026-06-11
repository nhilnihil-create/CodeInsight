#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int ans = min(k, a) - max(0, min(k-a-b, c));
  cout << ans << endl;
  return 0;
}
  