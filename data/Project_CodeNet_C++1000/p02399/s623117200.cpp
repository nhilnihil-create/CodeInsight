#include <stdio.h>
  
int main(void){
	int a,b,d,r;
	double f; 
    scanf("%d %d\n", &a, &b);
 
 	d = a/b;
 	r = a%b;
 	f = 1.0 * a/b ;
 
	printf("%d ",d);
	printf("%d ",r);
	printf("%.8lf\n",f);
     
    return 0;
} 