#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, D;
  cin >> N >> D;
  vector<vector<int64_t>> V(N, vector<int64_t>(2));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> V.at(i).at(j);
    }
  }
  int64_t count = 0LL;
  for (int i = 0; i < N; i++) {
    //cout << i << ' ' << V.at(i).at(0) * V.at(i).at(0) + V.at(i).at(1) * V.at(i).at(1) << endl;
    if (V.at(i).at(0) * V.at(i).at(0) + V.at(i).at(1) * V.at(i).at(1) <= D * D) {
      count++;
    }
  }
  cout << count << endl;
}