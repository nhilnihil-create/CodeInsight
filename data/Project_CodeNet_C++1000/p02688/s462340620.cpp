#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> d(M);
  vector<vector<int>> num(N, vector<int>(M));
  for (int i = 0; i < M; i++) {
    cin >> d.at(i);
    for (int j = 0; j < d.at(i); j++) {
      int k;
      cin >> k;
      num.at(k - 1).at(i) = 1;
    }
  }
  int count = 0;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < M; j++) {
      sum += num.at(i).at(j);
    }
    if (sum == 0) {
      count++;
    }
    sum = 0;
  }
  cout << count << endl;
}