#include <stdio.h>

int main(void)
{
  int i, j, k, H, W;

  for (i=0; ; i++){
    scanf("%d %d", &H, &W);

    if ( !H && !W)
      break;

    for (j = 0; j < H; j++){
      for ( k = 0; k < W; k++)
	printf("#");
      printf("\n");
    }
    printf ("\n");
  }

  return 0;
}

      