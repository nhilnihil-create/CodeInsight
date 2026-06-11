#include <cstdio>

int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}


int main()
{
  int x;
  scanf("%d",&x);
  printf("%d\n",360/gcd(x,360));
  return 0;
}
