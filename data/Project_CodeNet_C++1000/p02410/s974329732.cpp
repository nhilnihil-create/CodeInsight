#include<iostream>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  int a[101][101];
  int b[101];

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }

  for(int i=0;i<m;i++){
    cin >> b[i];
  }

  int sum[101];
  for(int i=0;i<n;i++){
    sum[i] = 0;
    for(int j=0;j<m;j++){
      sum[i] += a[i][j] * b[j];
    }
  }

  for(int i=0;i<n;i++){
    cout << sum[i] << endl;
  }

  return 0;
}