#include <stdio.h>
int main(void){
  int n, ans;
  scanf("%d", &n);
  if(n%2 == 0){
    ans = n/2;
  }
  else{
    ans = n/2 + 1;
  }
  printf("%d", ans);
  return 0;
}