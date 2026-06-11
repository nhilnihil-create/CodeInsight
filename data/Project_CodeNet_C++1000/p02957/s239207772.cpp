#include<bits/stdc++.h>
using namespace std;

int absolute(int N, int K){
  int x;
  x = N - K;
  if(x < 0){
    x = x * (-1);
  }
  return x;
}

int main(void){
  int A, B, K, max;
  int x[2];
  bool ans = false;
  cin >> A >> B;
  if(A > B)
    max = A;
  else
    max = B;
  for(int i = 0; i < max; i++){
    x[0] = absolute(A, i);
    x[1] = absolute(B, i);
    if(x[0] == x[1]){
      K = i;
      ans = true;
      break;
    }
  }
  if(ans) cout << K << "\n";
  else cout << "IMPOSSIBLE" << "\n";
  return 0;
}
