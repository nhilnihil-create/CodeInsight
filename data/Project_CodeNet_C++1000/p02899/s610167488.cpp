#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(2));
  for(int i = 0; i < N; i++) {
    A[i][1] = i;
    cin >> A[i][0];
  }

  sort(A.begin(), A.end());

  for(int i = 0; i < N; i++) {
    cout << A[i][1] + 1;
    if(i == N - 1) {
      cout << endl;
    }
    else {
      cout << " ";
    }
  }


  return 0;
}
