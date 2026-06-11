#include <cstdio>
#include <algorithm>

using namespace std;

int A[1000000];
int G[1000000/2];
int cnt;

void print(int A[], int n) {
  for (int i=0; i<n; i++) {
    printf("%d\n", A[i]);
  }
}

void insertionSort(int A[], int n, int g) {
  for (int i=g; i<n; i++) {
    int v = A[i];
    int j = i-g;
    while (j >= 0 && A[j] > v) {
      A[j+g] = A[j];
      j = j-g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int A[], int n) {
  int m = 0;
  G[0] = 1;
  while (G[m] <= n) {
    G[m+1] = 3*G[m]+1;
    m++;
  }
  printf("%d\n", m);
  for (int i=m-1; i>=0; i--) {
    printf("%d", G[i]);
    if (i > 0) putchar(' ');
  }
  putchar('\n');
  cnt = 0;
  for (int i=m-1; i>=0; i--) insertionSort(A, n, G[i]);
  printf("%d\n", cnt);
}

int main() {
  int N;
  scanf("%d", &N);
  for (int i=0; i<N; i++) scanf("%d", &A[i]);
  shellSort(A, N);
  print(A, N);
  return 0;
}