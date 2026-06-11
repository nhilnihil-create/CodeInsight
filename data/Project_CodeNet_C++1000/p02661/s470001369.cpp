#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)


int main() {
  int n; cin >> n;
  vector<ll> A(n), B(n);
  loop(i,0,n) cin >> A[i] >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  if (n&1) {
    ll x = A[n/2];
    ll y = B[n/2];
    cout << y-x+1 << endl;
    return 0;
  }

  ll x2 = A[(n/2)-1] + A[n/2];
  ll y2 = B[(n/2)-1] + B[n/2];
  ll ans = (y2/2 - (x2/2 + (x2%2!=0))) * 2 + 1;
  ans += x2&1;
  ans += y2&1;
  cout << ans << endl;
  return 0;
}
