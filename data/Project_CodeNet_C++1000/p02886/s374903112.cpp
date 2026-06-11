#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S=0;
  cin >> N;
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> V.at(i);
  }
  for (int i=1; i<N; i++) {
    for (int j=0; j<i; j++) {
      S += V.at(i) * V.at(j);
    }
  }
  cout << S << endl;
}