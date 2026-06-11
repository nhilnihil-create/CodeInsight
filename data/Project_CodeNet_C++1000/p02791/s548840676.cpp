#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007

int main() {
  int n, p;
  int ans = 0;
  cin >> n;
  int min = n + 2;
  rep(i, n) {
    cin >> p;
    if (p < min) {
      ans++;
      min = p;
    }
  }
  cout << ans << endl;

  return 0;
}
