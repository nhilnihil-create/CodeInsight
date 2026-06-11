#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int A[n][m], b[m], out[n] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      out[i] += A[i][j] * b[j];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << out[i] << endl;
  }
}