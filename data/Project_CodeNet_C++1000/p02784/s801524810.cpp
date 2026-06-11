#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int64_t H, N;
  cin >> H >> N;

  for (int64_t n = 0; n < N; ++n) {
    int64_t A;
    cin >> A;
    H -= A;
    if (H <= 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
