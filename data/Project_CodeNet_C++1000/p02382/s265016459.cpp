#include <cstdio>
#include <cmath>
	
int main(){
	int num, x[100],y[100];
	
	scanf("%d", &num);
	for(int i=0; i<num; ++i){
		scanf("%d", &x[i]);
	}	
	for(int i=0; i<num; ++i){
		scanf("%d", &y[i]);
	}
	
	for(int p=1; p<=3; ++p){
		double tmp = 0;
		for(int i=0; i<num; ++i){
			tmp += pow( fabs(x[i]-y[i]),p);
		}
		printf("%lf\n", pow(tmp,1.0/p));
	}
	
	double ma =0;
	for(int i=0; i<num; ++i){
		if(ma < fabs(x[i]-y[i])){
			ma = fabs(x[i]-y[i]);
		}
	}
	printf("%lf\n", ma);
	
	return 0;	
}
