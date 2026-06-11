#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H.at(i);
  int count = 0;
  int countmax = 0;
  for (int i = 0; i < N-1; i++) {
    if (H.at(i) >= H.at(i+1)) {
      count++;
      if (countmax < count) countmax = count;
    } else {
      count = 0;
    }
  }
  cout << countmax << endl;
}