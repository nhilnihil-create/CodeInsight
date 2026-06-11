#include <iostream>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main() {
  ll N, D[60]{}, A, ans{};
  cin >> N;
  while (cin >> A) {
    int i = 0;
    while (A) {
      D[i++] += A % 2;
      A >>= 1;
    }
  }  
  for (int i = 59; i >= 0; --i)
    ans = (ans * 2 + D[i] * (N - D[i])) % MOD;
  cout << ans << endl;
}
