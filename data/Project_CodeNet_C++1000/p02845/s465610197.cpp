#include <iostream>

using namespace std;

const int MAX = 100000;
const int MOD = 1000000007;

int main() {
  int N; cin >> N;

  int c[3] = {0};

  long long ans = 1;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;

    int res = 0;
    bool updated = false;
    for (int j = 0; j < 3; j++) {
      if (c[j] == a) {
        res++;
        if (!updated) {
          c[j]++;
          updated = true;
        }
      }
    }
    ans = ans * res % MOD;
  }

  cout << ans << endl;
}