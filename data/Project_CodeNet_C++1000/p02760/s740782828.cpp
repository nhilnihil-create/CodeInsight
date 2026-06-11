#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<vector<int>> b(3, vector<int>(3));
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      cin >> b[i][j];
    }
  }
  
  int n, number;
  cin >> n;
  
  for (int i=0; i<n; i++) {
    cin >> number;
    for(int j=0; j<3; j++) {
      for(int k=0; k<3; k++) {
        if(number == b[j][k]) {
          b[j][k] = 0;
        }
      }
    }
  }
  
  if(b[0][0] == b[1][0] && b[1][0] == b[2][0]) cout << "Yes" << endl;
  else if(b[0][1] == b[1][1] && b[1][1] == b[2][1]) cout << "Yes" << endl;
  else if(b[0][2] == b[1][2] && b[1][2] == b[2][2]) cout << "Yes" << endl;
  else if(b[0][0] == b[0][1] && b[0][1] == b[0][2]) cout << "Yes" << endl;
  else if(b[1][0] == b[1][1] && b[1][1] == b[1][2]) cout << "Yes" << endl;
  else if(b[2][0] == b[2][1] && b[2][1] == b[2][2]) cout << "Yes" << endl;
  else if(b[0][0] == b[1][1] && b[1][1] == b[2][2]) cout << "Yes" << endl;
  else if(b[0][2] == b[1][1] && b[1][1] == b[2][0]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}