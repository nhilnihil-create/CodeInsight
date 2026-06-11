#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  long long N, K, S;
  cin >> N >> K >> S;

  vector<long long> t(N);
  for (int i = 0; i < N; ++i) {
    if (K > 0) {
      t[i] = S;
      --K;
    } else
      if (S == 1000000000)
        t[i] = S - 1;
      else
        t[i] = S + 1;
  }

  for (int i = 0; i < N; ++i) {
    if (i != 0)
      cout << " ";
    cout << t[i];
  }
  cout << endl;

  return 0;
}