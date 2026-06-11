#include <bits/stdc++.h>
using namespace std;

int cnt;

void insertionSort(int A[], int n, int g) {
  for(int i = g; i <= n-1; ++i) {
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v) {
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(int A[], int n) {
  cnt = 0;
  int g[] = {797161, 265720, 88573, 29524, 9841, 3280, 1093, 364, 121, 40, 13, 4, 1};
  //int g[] = {531441, 177147, 59049, 19683, 6561, 2187, 729, 243, 81, 27, 9, 3, 1};
  int M = sizeof(g)/sizeof(int);
  vector<int> G;
  for(int i = M-1; i >= 0; --i) G.push_back(g[i]);
  int m = 0;
  while(m < M && G[m] <= n) ++m;
  G.resize(m);
  reverse(G.begin(), G.end());


  printf("%d\n", m);
  for(int i = 0; i < m; ++i) {
    if(i) printf(" ");
    printf("%d", G[i]);
  }
  printf("\n");

  for(int i = 0; i <= m-1; ++i) {
    insertionSort(A, n, G[i]);
  }
  printf("%d\n", cnt);
  for(int i = 0; i < n; ++i) {
    printf("%d\n", A[i]);
  }
}

int n;
int A[1000000];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) cin >> A[i];
  shellSort(A, n);
  return 0;
}