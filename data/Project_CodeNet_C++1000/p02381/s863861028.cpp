#include <stdio.h>
#include <math.h>



#ifndef DEBUG 
#define fprintf (void)
#endif 

double absval(double x);

int main(void){

	int n;
	int i;
	double sum,avg,var,ds;
	
	while(1){
		sum=0;
		var=0;
		scanf("%d",&n);
		
		if(n==0){
			break;
		}
		
		double s[n];
		
		for(i=0;i<n;i++){
			scanf("%lf",&s[i]);
			sum+=s[i];
			fprintf(stdout,"%lf\n",sum);
		}
		
		avg=sum/n;
		fprintf(stdout,"%lf\n",avg);
		
		for(i=0;i<n;i++){
			ds=avg-s[i];
			fprintf(stdout,"%lf\n",ds);
			var+=ds*ds;
			fprintf(stdout,"%lf\n",var);
		}
		
		printf("%lf\n",sqrt(var/n));
	}
	
	return 0;
}