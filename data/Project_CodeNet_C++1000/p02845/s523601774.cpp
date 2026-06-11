#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int R[3];
  R[0] = 0;
  R[1] = 0;
  R[2] = 0;
  ll ans = 1;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < 3; j++) {
      if (R[j] == A[i] && cnt == 0) {
        cnt++;
        R[j]++;
      } else if (R[j] == A[i]) {
        cnt++;
      }
    }
    ans *= cnt;
    ans %= Mod;
  }
  cout << (ans%Mod) << endl;
  return 0;
}
