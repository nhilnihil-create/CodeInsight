#include <stdio.h>

int main(void)
{
  int i, j, k, H, W;

  for (i=0; ; i++){
    scanf("%d %d", &H, &W);

    if ( !H && !W)
      break;

    if ((H==1) && (W==1)){
      printf("#\n\n");
      continue;
    }
    
    for (j=0; j < W; j++)
      printf("#");
    printf("\n");

    for (k=0; k < H-2; k++){
      printf("#");
      for (j=0; j < W-2; j++)
	printf(".");
      printf("#\n");
    }

    for (j=0; j < W; j++)
      printf("#");
    printf("\n");

    printf("\n");
  }

  return 0;
}