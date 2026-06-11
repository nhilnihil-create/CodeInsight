#include <stdio.h>

int main(void)
{
  int n,i;

  i = 0;
  while(i < 50){
    int ans = 0;
    scanf("%d", &n);
    if( n == -1){
      break;
    }
    if(n <= 36){
      for(int a = 0;a <= 9;a++){
	for(int b = 0;b <= 9;b++){
	  for(int c = 0;c <= 9;c++){
	    for(int d = 0;d <= 9;d++){
	      if((a+b+c+d) == n){
		ans++;
	      }
	    }
	  }
	}
      }
    }
    printf("%d\n", ans);
    i++;
  }
  return 0;
}