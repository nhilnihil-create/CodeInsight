#include<iostream>

using namespace std;

int main(){
  int K, N;
  cin >> K >> N;
  int A[N];
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }

  int d = 0;
  for (int i = 0; i < N - 1; i++){
    if(d < A[i+1] - A[i]){
      d = A[i+1] - A[i];
    }
  }

  if(d < (K - A[N-1] + A[0])){
      d = K - A[N-1] + A[0];
  }

  printf("%d\n", K - d);
}
