#include <cstdio>
#include <stdlib.h>
#include <math.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int main(){
	int n,x[100],y[100];
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&y[i]);
	}

	double m1=0,m2=0,m3=0,minf=0;
	for(int i = 0; i < n; i++){
		m1 += abs(x[i]-y[i]);
		m2 += pow(x[i]-y[i],2);
		m3 += pow(abs(x[i]-y[i]),3);
		minf = max(abs(x[i]-y[i]),minf);
	}
	m2 = sqrt(m2);
	m3 = pow(m3,1.0/3);

	printf("%.6f\n%.6f\n%.6f\n%.6f\n",m1,m2,m3,minf);

	return 0;
}