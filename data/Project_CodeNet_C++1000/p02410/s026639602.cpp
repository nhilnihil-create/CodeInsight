#include<iostream>
using namespace std;

int main() {

  int i1, i2, n, m, c;
  int A[101][101];
  int b[101];

  cin >> n >> m;

  for(i1 = 1; i1 <= n; i1++){
    for(i2 = 1; i2 <= m; i2++){
      cin >> A[i1][i2];
    }
  }

  for(i1 = 1; i1 <= m; i1++){
    cin >> b[i1];
  }

  for(i1 = 1; i1 <= n; i1++){
    for(i2 = 1; i2 <= m; i2++){
      c += A[i1][i2] * b[i2];
    }
    cout << c << endl;
    c = 0;
  }
  
  return 0;
  
}