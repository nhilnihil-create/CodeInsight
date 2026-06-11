#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

int main() {
  int N, K; cin >> N >> K;

  int A[N];
  int sum = 0;
  rep(i, N) {
    cin >> A[i];
    sum += A[i];
  }
  vi factors;
  for (int i = 1; i * i <= sum; ++i) {
    if (sum % i == 0) {
      factors.push_back(i);
      if (i * i != sum)
        factors.push_back(sum / i);
    }
  }
  all(sort, factors);
  all(reverse, factors);

  vi B(N);
  for (const auto& factor : factors) {
    int sum = 0; // 前のほう
    int sum2 = 0; // 後ろのほう
    rep(i, N) {
      B[i] = A[i] % factor;
      sum2 += (factor - B[i]) % factor;
    }
    all(sort, B);
    if (sum == sum2) {
      cout << factor << endl;
      return 0;
    }
    rep(i, N) {
      sum += B[i];
      sum2 -= (factor - B[i]) % factor;
      if (sum == sum2) {
        if (sum <= K) {
          cout << factor << endl;
          return 0;
        }
        break;
      }
    }
  }
  return 0;
}
