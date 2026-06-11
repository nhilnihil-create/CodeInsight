#include<stdio.h>
#include<math.h>
int ab(double);
int main(){
	int n, i;
	double D[4] = {0};
	double E[4] = {0};
	double pow2, pow3;
	scanf("%d", &n);
	double	x[100] = { 0 }, y[100] = { 0 };

	for (i = 0; i < n; i++){
		scanf("%lf", &x[i]);
	}
	for (i = 0; i < n; i++){
		scanf("%lf", &y[i]);
	}

	//p=1;
	for (i = 0; i < n; i++){
		pow2 = ab(x[i] - y[i]);
		D[0] += pow2;
		D[1] += pow(pow2, 2);
		D[2] += pow(pow2, 3);
	}
	E[0] = D[0];
	E[1] = sqrt(D[1]);
	E[2] = cbrt(D[2]);

	//p=00;
	for (i = 0; i < n; i++){
		if (D[3] < ab(x[i] - y[i])){
				D[3] = ab(x[i] - y[i]);
		}
	}
	E[3] = D[3];
	for (i = 0; i < 4; i++){
		printf("%lf\n",E[i]);
	}
	fscanf(stdin, "%d", &n);
	return 0;


}

int ab(double k){
	return (k > 0) ? k : -k;
}