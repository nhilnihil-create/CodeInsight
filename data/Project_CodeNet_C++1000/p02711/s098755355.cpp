#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  for(int i = 0; i < 3; i++) {
    if(N % 10 == 7) {
      puts("Yes");
      break;
    }
    else {
      N /= 10;
    }
  }
  if(N % 10 != 7) {
    puts("No");
  }
  return 0;
}