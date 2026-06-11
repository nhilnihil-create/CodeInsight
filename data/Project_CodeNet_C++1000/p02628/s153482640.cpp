/**
 *    author:  math2do
 *    created: 30.08.2020 16:45:21
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  } 
  sort(arr.begin(), arr.end());
  int ans = accumulate(arr.begin(), arr.begin() + k, 0);
  cout << ans << endl;
  return 0;
}
