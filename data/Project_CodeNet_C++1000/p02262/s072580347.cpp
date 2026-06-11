#include <cstdio>
#include <cmath>

int cnt;
int m;
int G[100];

void insertionSort(int* A, int n, int g){
  for(int i = g; i < n; i++){
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}
void shellSort(int* A, int n){
  cnt = 0;
  m = 1;
  while(pow(2, m) < n){
    m++;
    if(m == 100){
      break;
    }
  }
  G[m-1] = 1;
  for(int i = m - 2; i >= 0; i--){
    G[i] = G[i+1] * 2;
  }
  for(int i = 0; i < m; i++){
    insertionSort(A, n, G[i]);
  }
}

int main(){
  int n;
  int A[1000000];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  shellSort(A, n);
  printf("%d\n", m);
  for(int i = 0; i < m; i++){
    printf("%d", G[i]);
    if(i+1 == m) { printf("\n"); }
    else { printf(" "); }
  }
  printf("%d\n", cnt);
  for(int i = 0; i < n; i++){
    printf("%d\n", A[i]);
  }
}