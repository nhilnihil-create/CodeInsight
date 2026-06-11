#include <stdio.h>

int main(void)
{
  int n,i,a,b,c,d;

  i = 0;
  while(i < 50){
    int ans = 0;
    scanf("%d", &n);
    if(!(n > 0 && n <= 50)){
      break;
    }
    if(n <= 36){
      for(a = 0;a <= 9;a++){
	for(b = 0;b <= 9;b++){
	  for(c = 0;c <= 9;c++){
	    for(d = 0;d <= 9;d++){
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