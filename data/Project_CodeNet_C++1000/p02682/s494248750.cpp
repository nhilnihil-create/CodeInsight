#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int a,b,c,k;
  int ans = 0;
  cin >> a >> b >> c >> k;
  if(k <= a) ans = k;
  else if(k <= a+b) ans = a;
  else if(k <= a+b+c) ans = a - (k - a - b);
  cout << ans << endl;
}