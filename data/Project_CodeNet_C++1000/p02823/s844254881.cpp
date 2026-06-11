#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int64_t N, A, B;
  cin >> N >> A >> B;

  int64_t diff = abs(A - B);
  if (diff % 2 == 0) {
    cout << diff / 2 << endl;
    return 0;
  }

  int64_t answer;
  if (B < A) swap(A, B);
  if ((A - 1) <= (N - B)) {
    answer = A - 1 + 1;
    answer += (B - A) / 2;
  } else {
    answer = N - B + 1;
    // N - (A + N - B + 1)
    answer += (B - A - 1) / 2;
  }
  cout << answer << endl;
  return 0;
}