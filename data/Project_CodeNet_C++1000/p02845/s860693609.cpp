#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }

  const int64_t mod = 1e9 + 7;
  int64_t answer = 1;
  int hats[3] = {0, 0, 0};
  rep(i, N) {
    int idx = 0;
    int cases = 0;
    rep(j, 3) {
      if (A[i] == hats[j]) {
        idx = j;
        cases++;
      }
    }
    answer = (answer * cases) % mod;
    hats[idx]++;
  }
  cout << answer << endl;
  return 0;
}
