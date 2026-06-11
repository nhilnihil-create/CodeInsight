#include <stdio.h>

int main() {
  long long int n;
  scanf("%lld", &n);

  int i = 0;
  char c[50];
  while(n > 0) {
    c[i] = --n % 26 + 'a';
    n /= 26;
    i++;
  }

  for(int j = i - 1; j >= 0; j--) {
    printf("%c", c[j]);
  }
  return 0;
}
