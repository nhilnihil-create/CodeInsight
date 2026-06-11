#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int dp [N][2];
int arr [N];
int n;

int solve (int p, bool changed) {
  if (p >= n) return true;
  int &res = dp[p][changed];
  if (~res) return res;
  res = 0;
  int ant = arr[p - 1] - changed;
  if (arr[p] < ant) return 0;
  if (arr[p] == ant) {
    res |= solve (p + 1, 0);
  } else {
    res |= solve (p + 1, 0);
    res |= solve (p + 1, 1);
  }
  return res;
}

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  memset (dp, -1, sizeof(dp));
  cout << (solve (1, false)?"Yes":"No") << '\n';
  return 0;
}
