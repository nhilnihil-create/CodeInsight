#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int a[N+1], b[N+1];
  for (int i = 1; i < N + 1; i++){
    cin >> a[i];
    b[i] = 1;
  }

  for (int i = N; i > 0; i--){
    int s=0;
    for (int j = i; j < N + 1; j+=i){
      s += b[j];
    }
    if (a[i] != s%2){
      b[i] = 0;
    }
  }

  int M = 0;
  for (int i = 1; i < N + 1; i++){
    M += b[i];
  }

  printf("%d\n", M);
  if (M > 0){
    for (int i = 0; i < N + 1; i++){
      if (b[i]==1) printf("%d ", i);
    }
    printf("\n");
  }
  
  
}
