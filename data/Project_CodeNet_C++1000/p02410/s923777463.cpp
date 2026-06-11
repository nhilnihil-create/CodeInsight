#include<iostream>
#include<cstdio>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int A[n][m] = {0};
  int B[m] = {0};
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int r;
      cin >> r;
      A[i][j] = r;
    }
  }

  for(int j = 0; j < m; j++) {
    int r;
    cin >> r;
    B[j] = r;
  }

  for (int i = 0; i < n; i++) {
    int r = 0;
    for(int j = 0; j < m; j++) {
      r += A[i][j] * B[j];
    }
    cout << r << endl;
  }

}