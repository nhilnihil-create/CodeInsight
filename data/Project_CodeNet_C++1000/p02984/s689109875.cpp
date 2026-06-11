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
  ll ans[N];
  ll oddsum = 0;
  for (int i = 1; i < N; i+=2) {
    oddsum += A[i];
  }
  ans[0] = sum - (oddsum * 2);
  for (int i = 0; i < N - 1; i++) {
    ans[i + 1] = (2 * A[i]) - ans[i];
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}