#include <iostream>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  int res = 0;
  while (N) {
    N /= K;
    ++res;
  }
  cout << res << endl;
}