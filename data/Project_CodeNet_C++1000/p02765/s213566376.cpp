#include <stdio.h>

int main()
{
  int N;
  int R;
  int K;
  
  scanf("%d %d", &N, &R);
  
 
  if (N < 10) {
	K = 100 * (10 - N);
    printf("%d", R + K);
  }
  else {
    printf("%d", R);
  }
 
  return 0;
}