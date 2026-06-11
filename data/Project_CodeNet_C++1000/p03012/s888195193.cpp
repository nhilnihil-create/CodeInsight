#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> W(N);
  for (int i = 0; i < N; i++) cin >> W.at(i);
  int sumL = W.at(0);
  int sumR = 0;
  for (int i = 1; i < N; i++) sumR += W.at(i);
  int diffmin;
  diffmin = abs(sumR - sumL);
  for (int i = 1; i < N-1; i++) {
    sumL += W.at(i);
    sumR -= W.at(i);
    if (diffmin > abs(sumR - sumL)) {
      diffmin = abs(sumR - sumL);
    }
  }
  cout << diffmin << endl;
}