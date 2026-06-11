#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
  int N, K;
  cin >> N >> K;
  
  std::vector<int> H;
  for (int i=0; i < N; ++i) {
    int h;
    cin >> h;
    H.push_back(h);
  }

  std::sort(begin(H), end(H));

  if (K >= N) {
    cout << 0 << endl;;
  } else {
    long sum = 0;
    for (int i = 0; i < N - K; ++i) {
      sum += H[i];
    }
    cout << sum << endl;
  }
  return 0;
}
