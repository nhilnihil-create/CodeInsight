
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

double minkowskiDist(int n,int p,double *x,double *y){
	double sum = 0;
	for(int i = 0; i < n; i++){
		sum += pow( fabs(x[i] - y[i]) , p);
	}
	return pow( sum, 1.0/p);
}

double chebychevDist(int n,double *x,double *y){
	double max = fabs(x[0] - y[0]);
	for(int i = 1; i < n; i++){	//top of the hill????????£????????§???????±???????
		if( max < fabs(x[i] - y[i])) max = fabs(x[i] - y[i]);
	}
	return max;
}

int main()
{
	int n;
	cin>>n;
	double *x = new double[n];
	double *y = new double[n];
	for(int i = 0; i < n; i ++) cin>>x[i];
	for(int i = 0; i < n; i ++) cin>>y[i];
	printf("%.6lf\n", minkowskiDist(n,1,x,y));
	printf("%.6lf\n", minkowskiDist(n,2,x,y));
	printf("%.6lf\n", minkowskiDist(n,3,x,y));
	printf("%.6lf\n", chebychevDist(n,x,y));
	delete x;
	delete y;
	return 0;
}