#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int a;
  cin >> a;
  ll b, n;
  cin >> b >> n;
  ll x = min(n, b-1);
  ll ans = a*x / b;
  
  cout << ans << endl;
  return 0;
}