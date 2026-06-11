#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,D;
  cin >> N >> D;
  vector<vector<int>> V(N,vector<int>(D));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++)
      cin >> V.at(i).at(j);
  }
  int count = 0;
  
  for (int k = 0; k < N - 1; k++) {
    for (int l = k + 1; l < N; l++) {
      int a = 0;
      for (int m = 0; m < D; m++)
        a += (V.at(k).at(m) - V.at(l).at(m))*(V.at(k).at(m) - V.at(l).at(m));
      for (int n = 1; n < sqrt(a) + 1; n++) {
        if (n*n == a)
          count++;
      }
    }
  }
  
  cout << count << endl;
      
}