#include <stdio.h>
#include<math.h>
int main(void){
  while(1){
      int  n,i;
      scanf("%d",&n);
      
      if(n==0)
      break;
      double a[n],avg=0,b=0;
      for(i=0;i<n;i++){
          scanf("%lf",&a[i]);
          avg+=a[i];
      }
      avg/=(double)n;
      for(i=0;i<n;i++){
          b+=(a[i]-avg)*(a[i]-avg);
      }
      
      printf("%lf\n",sqrt(b/n));
  }
}