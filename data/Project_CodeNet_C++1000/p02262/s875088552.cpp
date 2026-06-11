#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


long long cnt;
int MAX = 1000000;
vector<int> G;

void insertSort(int A[], int n, int g) {
  int j, i, v;
  for ( i = g; i < n; i++ ) {
    v = A[i];
    j = i - g;
    while ( j >= 0 && A[j] > v ) {
      A[j + g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(int A[], int n) {
  for (int h = 1; ; ) {
    if (h > n) break;
    G.push_back(h);
    h = 3*h + 1;
  }

  for ( int i = G.size()-1; i>=0; i--) {
    insertSort(A, n, G[i]);
  }
}

int main() {
	int A[MAX], n;
  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) scanf("%d", &A[i]);

  cnt = 0;

  shellSort(A, n);

  printf("%lu\n", G.size());
  for ( int i = G.size()-1; i>=0; i--) {
    printf("%d", G[i]);
    if (i) printf(" ");
  }
  printf("\n");
  printf("%llu\n", cnt);
  for ( int i = 0; i < n; i++ ) printf("%d\n", A[i]);

  return 0;
}

