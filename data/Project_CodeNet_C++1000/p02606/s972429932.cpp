#include<stdio.h>
int l, r, d;
int main(){
  scanf("%d %d %d", &l, &r, &d);
  printf("%d\n", r/d-(l-1)/d);
  return 0;
}
