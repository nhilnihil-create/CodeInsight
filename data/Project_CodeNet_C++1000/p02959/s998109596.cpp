#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;


int main() {
  int n; cin >> n;
  vector<ll> a(n+1);
  vector<ll> b(n);
  rep(i,n+1) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll ans = 0;
  rep(i,n){
    int left = min(a[i],b[i]);
    ans += left;
    a[i] -= left;
    b[i] -= left;

    int right = min(a[i+1],b[i]);
    ans += right;
    a[i+1] -= right;
    b[i] -= right;
  }
  cout << ans << endl;
  return 0;
}