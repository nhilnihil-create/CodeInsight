#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  int N;
  cin >> K >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }

  int dmax = K - vec[N - 1] + vec[0];

  for (int i = 0; i < N - 1; i++) {
    int d = vec[i + 1] - vec[i];
    dmax = max(d, dmax);
  }

  cout << K - dmax << endl;
}