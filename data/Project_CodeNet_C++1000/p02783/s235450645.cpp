#include<stdio.h>
int main()
{
  int H,A;
  scanf("%d", &H);
  scanf("%d", &A);

  int I=0;
  for(; H>0;)
  { 
    H=H-A;
    I=I+1;
  }
  printf("%d",I);
  return 0;
}