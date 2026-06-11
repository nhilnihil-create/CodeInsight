#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll n;
  cin >> n;
  ll a[n], i, j;
  for(i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    if(a[i] == 0) {
      cout << "0";
      return 0;
    }
  }
  long double ans = 0;
  for(i = 0; i < n; i++) {
    ans += log10(a[i]);
  }
  if(ans > 18) {
    cout << "-1";
    return 0;
  }
  ll final_ans = 1;
  for(i = 0; i < n; i++) {
    final_ans *= a[i];
  }
  if(final_ans > (ll)(1e18)) {
    final_ans = -1;
  }
  cout << final_ans;
}