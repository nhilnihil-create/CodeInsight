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

    for (j=0; j < H/2; j++){
      for (k=0; k < W/2; k++)
	printf("#.");
      if (W%2)
	printf("#");
      printf("\n");
      
      for (k=0; k < W/2; k++)
	printf(".#");
      if (W%2)
	printf(".");
      printf("\n");
    }
    if (H%2){
      for (k=0; k < W/2; k++)
	printf("#.");
      if (W%2)
	printf("#");
      printf("\n");
    }

    printf("\n");
  }

  return 0;
}

      