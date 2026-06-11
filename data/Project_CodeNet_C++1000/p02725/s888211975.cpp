#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll k, n, ans;
  cin >> k >> n;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ans = arr[n-1] - arr[0];
  for (int i = 1; i < n; i++) {
    ans = min(ans, arr[i-1] + k - arr[i]);
  }
  cout << ans;
}