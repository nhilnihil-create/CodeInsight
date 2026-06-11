#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> V(3,vector<int>(N));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < N; j++)
      cin >> V.at(i).at(j);
  }
  
  int count = 0;
  for (int k = 0; k < N; k++) {
    count += V.at(1).at(V.at(0).at(k) - 1);
    
    if (k < N - 1) {
      if (V.at(0).at(k) == V.at(0).at(k + 1) - 1)
        count += V.at(2).at(V.at(0).at(k) -1);
    }
  }
  
  cout << count << endl;
}
