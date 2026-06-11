#include "bits/stdc++.h"
using namespace std;
int main() {
  int n; cin >> n;
  int arr[n][2];
  for (int i = 0; i < n; i ++) cin >> arr[i][0] >> arr[i][1];
  bool f[n];
  for (int i = 0; i < n; i ++) f[i] = arr[i][0] == arr[i][1];
  for (int i = 0; i < n - 2; i ++) if (f[i] && f[i + 1] && f[i + 2]) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}