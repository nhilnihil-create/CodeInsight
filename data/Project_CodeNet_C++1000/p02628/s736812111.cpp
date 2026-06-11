#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector <int> arr(n);
  for (auto &m: arr) {
    cin >> m;
  }
  int res = 0;
  sort(arr.begin(),arr.end());
  for (int i = 0; i < k; i++ ) {
    res += arr[i];
  }
  cout << res;
}