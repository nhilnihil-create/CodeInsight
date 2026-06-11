#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int>> data(N, vector<int> (D));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < D; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int count = 0;
  for(int i = 0; i < N - 1; i++) {
    for(int j = i + 1; j < N; j++) {
      int sum = 0;
      for(int k = 0; k < D; k++) {
        sum += pow(data.at(i).at(k) - data.at(j).at(k), 2);
      }
      for(int k = 1; k * k <= sum; k++) {
        if(k * k == sum) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
}
