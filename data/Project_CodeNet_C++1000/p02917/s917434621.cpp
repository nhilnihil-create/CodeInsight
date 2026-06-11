#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int64_t> B(N-1);
  for (int i = 0; i < N-1; i++) cin >> B.at(i);
  int64_t sum = 0;
  sum += B.at(0) + B.at(N-2);
  for (int i = 0; i < N-2; i++) {
    sum += min(B.at(i), B.at(i+1));
  }
  cout << sum << endl;
}