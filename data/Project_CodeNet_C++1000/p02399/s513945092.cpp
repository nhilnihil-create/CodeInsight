#include<cstdio>

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  int d = a/b, r = a%b;
  double f = (double)a / b;
  printf("%d %d %f", d, r, f);
  return 0;
}