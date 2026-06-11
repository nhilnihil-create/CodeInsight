#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007

int main() {
  int h, n, a;
  int suma = 0;
  string ans;
  cin >> h >> n;
  rep(i, n) {
    cin >> a;
    suma += a;
  }
  if (suma >= h) ans = "Yes";
  else ans = "No";
  cout << ans << endl;

  return 0;
}
