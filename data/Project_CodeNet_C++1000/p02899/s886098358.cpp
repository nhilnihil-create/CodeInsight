#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> A.at(i).at(0);
    A.at(i).at(1) = i + 1;
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++) {
    cout << A.at(i).at(1) << " ";
  }
  cout << endl;
  
}