#include <stdio.h>

main(){
  int a, d = 0, s = 1, n, dta[251];
  
  scanf("%d", &n);
  for(a=1;a<=n;a++) scanf("%d", &dta[a]);
  for(a=1;a<=n;a++){
    printf("node %d: key = %d, ", a, dta[a]);
    
    if(a/2) printf("parent key = %d, ", dta[a/2]);
    if(2*a<=n) printf("left key = %d, ", dta[2*a]);
    if(2*a+1<=n) printf("right key = %d, ", dta[2*a+1]);
    
    printf("\n");
  }
  
  return 0;
}

