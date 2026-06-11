#include <iostream>

using namespace std;

int main(){
  int X, N=100004;
  cin >> X;
  int A[N];
  for (int i = 0; i < N; i++){
    A[i] = 1;
  }
  A[0] = A[1] = 0;
  for (int i = 2; i * i < N; i++){
    if (A[i]==1){
      for (int j = i * i; j < N; j+=i){
        A[j] = 0;
      }
    }
  }
  
  for (int i = X; i < N; i++){
    if(A[i]==1){
      printf("%d\n", i);
      break;
    }
  }
}
