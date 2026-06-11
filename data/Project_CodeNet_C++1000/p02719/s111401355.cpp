#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  if (N == K) {
    cout << 0 << endl;
  } else if (N < K) {
    cout << min(N, K-N) << endl;
  } else {
    cout << min(N-(N/K)*K, ((N/K)+1)*K-N) << endl;
  }
}
