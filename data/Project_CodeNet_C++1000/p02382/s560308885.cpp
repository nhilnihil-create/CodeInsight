#include <stdio.h>
#include <math.h>



#ifndef DEBUG 
#define fprintf (void)
#endif 

double absval(double x);

int main(void){

	int n,i,j,p;
	
	scanf("%d",&n);
	
	double vect[2][n];
	double d[n];
	double sum;
	double max=0;
	
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&vect[i][j]);
		}
	}

	for(j=0;j<n;j++){
		d[j]=fabs(vect[0][j]-vect[1][j]);
	}
	
	for(p=1;p<4;p++){
		sum=0;
		for(j=0;j<n;j++){
			sum+=pow(d[j],p);
		}
		printf("%lf\n",pow(sum,1.0/p));
	}
	
	for(j=0;j<n;j++){
		if(d[j]>max){
			max=d[j];
			fprintf(stdout,"%lf",max);
		}
	}
	
	printf("%lf\n",max);
	
	return 0;
}