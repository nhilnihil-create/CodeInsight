#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);
  int count = 1;
  int minp = P.at(0);
  for (int i = 1; i < N; i++) {
    if (minp > P.at(i)) {
      count++;
      minp = P.at(i);
    }
  }
  cout << count << endl;
}