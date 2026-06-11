#include <stdio.h>

int main(void) {
 int k, a, b;

 scanf("%d", &k);
 scanf("%d%d", &a, &b);

 int largest = (b / k) * k;
 if (a <= largest) {
 puts("OK");
 } else {
 puts("NG");
 }

 return 0;
 }