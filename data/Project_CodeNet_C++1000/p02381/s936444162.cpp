#include <stdio.h>
#include <math.h>
#include <new>

int main(void)
{
  int n;
  double a;
  int i;
  
  while(1){
    double sum=0;
    double m; //??????
    double to=0; //??????
    
    scanf("%d",&n);
    if(n==0){
      break;
    }
    
    double *s = new double[n]; //????????????????¢????
    for(i=0; i<n; i++){
      scanf("%lf",&s[i]);
      sum=sum + s[i];
    }
    m = sum / n;

    for(i=0; i<n; i++){
      if(s[i]>m){
	to =to + ((s[i] - m) * (s[i] - m));
      }else{
	to =to + ((m - s[i]) * (m - s[i]));
      }
    }

    a = sqrt(to/n);

    printf("%f\n",a);
    
    delete[] s;
  }
    
  return(0);
}