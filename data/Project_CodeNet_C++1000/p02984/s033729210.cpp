#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  long long A[N], y[N];
  int s = 0, As=0;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    s += A[i];
    if ((i+1)%2==0) As += A[i];
  }

  y[0] = s - 2 * As;
  for (int j = 1; j < N; j ++) {
    y[j] = A[j-1] * 2 - y[j-1];
  }

  
  for (int i = 0; i < N; i++){
    printf("%llu ", y[i]);
  }
  printf("\n");
  
  
}
