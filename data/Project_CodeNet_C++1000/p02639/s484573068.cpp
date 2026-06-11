#include <cstdio>
int main() {
  int x;
  int i=1;
  while(i < 6) {
    scanf("%d", &x);
    if(x == 0) {
      printf("%d", i);
      break;
    }
    i++;
  }
  return 0;
}