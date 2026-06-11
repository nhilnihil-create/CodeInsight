#include <cstdio>
#include <vector>
using namespace std;

long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

void insertionSort(int A[], int n, int g) {
  for (int i = g; i < n; ++i) {
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(int A[], int n) {
  for (int h = 1; h <= n; h = 3*h + 1)
    G.push_back(h);
  for (int i = G.size() - 1; i >= 0; --i)
    insertionSort(A, n, G[i]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &A[i]);
  cnt = 0;
  
  shellSort(A, n);
  
  printf("%ld\n", G.size());
  for (int i = G.size() - 1; i > 0; --i)
    printf("%d ", G[i]);
  printf("%d\n", G[0]);
  printf("%lld\n", cnt);
  for (int i = 0; i < n; ++i)
    printf("%d\n", A[i]);
    
  return 0;
}