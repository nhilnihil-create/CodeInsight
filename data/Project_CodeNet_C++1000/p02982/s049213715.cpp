#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  int A[n][d];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < d; j++){
      cin >> A[i][j];
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int tmp = 0;
      for(int k = 0; k < d; k++){
        int b = abs(A[i][k] - A[j][k]);
        tmp += b*b;
      }
      bool judge = false;
      for(int k = 0; k <= tmp; k++){
        if(k*k == tmp) ans++;
      }
    }
  }
  cout << ans << endl;
        
        
        
  
}
