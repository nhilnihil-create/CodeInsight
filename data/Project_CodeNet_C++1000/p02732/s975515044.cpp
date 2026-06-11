#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;


int main() {
  int n;
  cin >> n;
  vector<ll> d(n+1);
  vector<ll> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[a[i]]++;
  }
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += d[i]*(d[i]-1)/2;
  }
  for (int i = 1; i <= n; i++) {
    ll ans = sum;
    ans -= d[a[i]]*(d[a[i]]-1)/2;
    ans += (d[a[i]]-1)*(d[a[i]]-2)/2;
    cout << ans << endl;
  }

  return 0;
}