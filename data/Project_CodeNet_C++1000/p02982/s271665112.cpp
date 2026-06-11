#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);
// int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
// int a[12][12];
//平方根　= sqrt




void solve() {
  int n,d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep(i,n) {
    rep(j,d) cin >> x[i][j];
  }

  int ans =0;
  rep(i,n)rep(j,i) { // j<i
    int sq =0;
    rep(k,d) {
      int diff = x[i][k] - x[j][k];
      sq += diff * diff;
    }
    int s = sqrt(sq) + 0.5; // 1.9999....
    if (s*s == sq) ans++;
  }
  cout << ans << endl;
  return ;

}

int main() {
  solve();
  return 0;
}
