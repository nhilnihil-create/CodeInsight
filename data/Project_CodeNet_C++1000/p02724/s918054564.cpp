#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  long long int X,a,b,c,ans;
  cin >> X;
  a = X % 500;
  b = X / 500;
  c = a / 5;
  ans = 0;
  ans += c*5;
  ans += b*1000;
  cout << ans << endl;
}