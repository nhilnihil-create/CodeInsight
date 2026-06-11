#include <cstdio>
using namespace std;

int main() {
  int a[33] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51}, k;
  scanf("%d", &k);
  printf("%d", a[k-1]);
  return 0;
}