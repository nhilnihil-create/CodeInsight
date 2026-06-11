#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  int ans = 0;
  if(n <= 9)ans = n;
  else if(n <= 99)ans = 9;
  else if(n <= 999)ans = 9 + n - 99;
  else if(n <= 9999)ans = 909;
  else if(n <= 99999)ans = 909 + n -9999;
  else ans = 90909;
  cout << ans << endl;
}
  