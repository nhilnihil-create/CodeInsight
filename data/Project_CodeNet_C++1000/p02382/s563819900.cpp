#include<cstdio>
#include<cmath>

int main(){
	int n;
	double x[1000], y[1000];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lf", &x[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%lf", &y[i]);
	}

	double d;
	for(int j = 0; j < 3; j++){
		d = 0;
		for(int i = 0; i < n; i++){
			d += pow(fabs(x[i] - y[i]), j + 1);
		}
		printf("%lf\n", pow(d, 1.0 / (j + 1)));
	}

	d = 0;
	for(int i = 0; i < n; i++){
		if(fabs(x[i] - y[i]) > d){
			d = fabs(x[i] - y[i]);
		}
	}
	printf("%lf\n", d);
	return 0;
}