#include <stdio.h>
int main(void)
{
  int H,W,h,w,k;
  for ( ; ; )
  {
    scanf("%d %d",&H,&W);
    if (H == 0 && W == 0)
    {
      break;
    }
    for (h = 1; h <= H; h++)
    {
      for (w = 1; w <= W; w++)
      {
        k = h + w;
        if (k % 2 == 0)
        {
          printf("#");
        }else{
          printf(".");
        }
        if (w == W)
        {
          printf("\n");
        }
      }
      if (h == H)
      {
        printf("\n");
      }
    }
  }
  return 0;
}

