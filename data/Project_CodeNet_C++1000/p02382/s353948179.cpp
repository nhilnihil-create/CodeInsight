#include <stdio.h>
#include <math.h>
int main(void){
	int n,x[100],y[100],i,t;
	double d1=0,d2=0,d3=0,di=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&y[i]);
	}
	for(i=0;i<n;i++){
		t=x[i]-y[i];
		if(t<0)
			t=-t;
		d1+=t;
		d2+=t*t;
		d3+=t*t*t;
		if(di<t) di=t;
	}
	d2=pow(d2,1./2);
	d3=pow(d3,1./3);
	printf("%.6f\n%.6f\n%.6f\n%.6f\n",d1,d2,d3,di);
	return 0;
}