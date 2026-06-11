#include <stdio.h>
#include <string.h>

int main() {
  int K;
  char str[101];
  scanf("%d %[^\n]",&K, str);
  int len = strlen(str);

  if(len <= K) {
    printf("%s", str);
  }
  else {
    for(int i = 0; i < K; i++) {
      printf("%c", str[i]);
    }
    printf("...");
  }

  return 0;
}