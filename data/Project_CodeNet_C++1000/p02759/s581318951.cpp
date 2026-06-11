#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  if(n == 1) ans = 1;
  else if(n % 2 == 0) ans = n / 2;
  else if(n % 2 != 0) ans = (n / 2) + 1;
  cout << ans << endl;
  return 0;
}
    