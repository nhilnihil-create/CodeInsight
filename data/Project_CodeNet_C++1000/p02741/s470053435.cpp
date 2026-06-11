#include <stdio.h>

int main() {
 const int num[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
 int k=1;
 scanf("%d", &k);
 printf("%d", num[k-1]);
 return 0;
}