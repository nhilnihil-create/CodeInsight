#include <stdio.h>
int main(void)
{
  int H,W,h,w;
  for ( ; ; )
  {
    scanf("%d %d",&H,&W);
    if (H == 0 && W == 0)
    {
      break;
    }
    for (h = 1; h <= H; h++)
    {
      if (h == 1 || h == H)
      {
        for (w = 1; w <= W; w++)
        {
          printf("#");
          if (w == W)
          {
            printf("\n");
          }
          if (w == W && h == H)
          {
            printf("\n");
          }
        }
      }else{
        for (w = 1; w <= W; w++)
        {
          if (w == 1 || w == W)
          {
            printf ("#");
            if (w == W)
            {
              printf("\n");
            }
          }else{
            printf(".");
          }
        }
      }
    }
  }
  return 0;
}

