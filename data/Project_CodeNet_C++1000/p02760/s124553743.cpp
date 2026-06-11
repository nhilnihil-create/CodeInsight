#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> A(3, vector<int>(3));
  int N;
  vector<int> b(N);
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cin >> A.at(i).at(j);
    }
  }
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> b.at(i);
    for (int j=0; j<3; j++) {
      for (int k=0; k<3; k++) {
        if (A[j][k] == b.at(i)) {
          A[j][k] = -1;
        }
      }
    }
  }
  vector<int> a1={A[0]};
  vector<int> a2={A[1]};
  vector<int> a3={A[2]};
  vector<int> a4={A[0][0], A[1][0], A[2][0]};
  vector<int> a5={A[0][1], A[1][1], A[2][1]};
  vector<int> a6={A[0][2], A[1][2], A[2][2]};
  vector<int> a7={A[0][0], A[1][1], A[2][2]};
  vector<int> a8={A[0][2], A[1][1], A[2][0]};
  vector<int> t={-1,-1,-1};
  if (a1==t || a2==t || a3==t || a4==t || a5==t || a6==t || a7==t || a8==t) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}