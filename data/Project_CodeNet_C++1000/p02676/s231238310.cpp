#include <stdio.h>
#include <string.h>

int main() {
  int n;
  char str[255];

  scanf("%d", &n); getchar();
  scanf("%s", str);

  int len = strlen(str);
  if(len > n) {
    for(int i = 0; i < n; i++) {
      printf("%c", str[i]);
    }
    puts("...");
  } else {
    printf("%s\n", str);
  }
}