#include <bits/stdc++.h>
using namespace std;

bool integer(double x) {
  while (1 <= x) {
    x -= 1;
  }
  if (x == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int>> X(N, vector<int>(D));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> X.at(i).at(j);
    }
  }
  int count = 0;
  for (int i = 0; i < N-1; i++) {
    for (int j = i + 1; j < N; j++) {
      double dist2 = 0;
      for (int k = 0; k < D; k++) {
        dist2 += pow(X.at(i).at(k) - X.at(j).at(k), 2);
      }
      double dist = sqrt(dist2);
      if (integer(dist)) {
        count++;
      }
    }
  }
  cout << count << endl;
}