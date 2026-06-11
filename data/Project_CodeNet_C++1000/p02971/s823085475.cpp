#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N], max_A = 0, max_i = 0, next_A = 0;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    if (A[i] > max_A){
      max_A = A[i];
      max_i = i;
    }
  }

  for (int i = 0; i < N; i++){
    if (A[i] > next_A && i != max_i){
      next_A = A[i];
    }
  }
  
  for (int i = 0; i < N; i++){
    if (i == max_i){
      printf("%d\n", next_A);
    }else{
      printf("%d\n", max_A);
    }
  }
  
  
}

