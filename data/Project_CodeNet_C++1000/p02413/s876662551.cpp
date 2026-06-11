#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int x[n][m], y[m] = {}, sum;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < m; j++) {
      cout << x[i][j] << ' ';
      sum += x[i][j];
      y[j] += x[i][j];
    }
    cout << sum << endl;
  }
  sum = 0;
  for (int j = 0; j < m; j++) {
    cout << y[j] << ' ';
    sum += y[j];
  }
  cout << sum << endl;
}