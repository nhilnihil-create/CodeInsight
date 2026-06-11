// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  int n; cin >> n;
  vector<ll> A(n);
  loop(i,0,n) cin >> A[i];
  map<int, int> M;
  ll ans = 0;
  loop(i,1,n+1) {
    ll v = i+A[i-1];
    if (i==1) {
      if (v<200000) M[v]++;
      continue;
    }
    ll val = i - A[i-1];
    if (val >= 0) {
      ans += M[val];
    }
    if (v<200000) M[v]++;
  }
  cout << ans << endl;
  return 0;
}
