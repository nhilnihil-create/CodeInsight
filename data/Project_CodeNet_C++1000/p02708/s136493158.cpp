#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  ll int n, k;
  cin >> n >> k;
  ll int ans = 0;
  
  for(ll int i = k; i <= n+1; ++i) {
    ll int start = i*(i+1)/2;
    ll int end = i*(n+n-i+3)/2;
    ans += end-start+1;
//    cout << start << " " << end << endl;
    ans %= 1000000007;
  }
  
  cout << ans << endl;
  return 0;
}
