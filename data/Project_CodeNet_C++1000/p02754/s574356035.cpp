#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, A, B, R, ans = 0;
  cin >> N >> A >> B;
  ans = (N / (A + B)) * A;
  R = N % (A + B);
  ans += min(A, R);
  cout << ans << endl;
}