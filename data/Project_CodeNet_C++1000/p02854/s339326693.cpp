#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }
  ll ans = 999999999999;
  ll left = A[0];
  ll right = sum - A[0];
  for (int i = 1; i < N; i++) {
    ll res = abs(right - left);
    ans = min(ans,res);
    left += A[i];
    right -= A[i];
  }
  cout << ans << endl;
  return 0;
}