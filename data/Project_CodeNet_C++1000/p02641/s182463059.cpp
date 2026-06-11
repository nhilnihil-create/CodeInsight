/**
 *    author:  math2do
 *    created: 26.08.2020 15:19:22
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int x, n;
  cin >> x >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  } 
  sort(arr.begin(), arr.end());
  int dif = (int) 1e9;
  int ans = -1;
  for (int i = -1001; i <= 1001; i++) {
    if (!binary_search(arr.begin(), arr.end(), i)) {
      if (abs(x - i) < dif) {
        dif = abs(x - i);
        ans = i;
      } 
    } 
  } 
  cout << ans << endl;
  return 0;
}
