#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<float.h>
#include<math.h>
#include<algorithm>
using namespace std;


double Manhattan(int *x, int *y, int n){
	double d=0;
	for(int i=0; i<n; i++){
		d+=abs(x[i]-y[i]);
	}
	return d;
}

double Euclidean(int *x, int *y, int n){
	double d, tmp=0.0;
	for(int i =0; i<n; i++){
		tmp+=pow((double)abs(x[i]-y[i]),2.0);		//d+=abs(x[i]-y[i])*abs(x[i]-y[i])
	}
	d=pow(tmp, 1.0/2.0);
	//cout<<pow((double)abs(x[1]-y[1]),1.0/2.0)<<endl;
	return d;
}	

double Minkowski3(int *x, int *y, int n){
	double d, tmp=0.0;
	for(int i =0; i<n; i++){
		tmp+=pow((double)abs(x[i]-y[i]),3.0);
	}
	d=pow(tmp,1.0/3.0);
	return d;
}

double Chebyshev(int *x, int *y, int n){
	double d=0;
	int sub[100]={0};
	for(int i=0; i<n; i++){
		sub[i]=abs(x[i]-y[i]);
		if(sub[i]>d)d=sub[i];
	}
	return d;
}


int main(){
	int n, x[100]={0},y[100]={0};
	double a1, a2, a3, a4;

	cin>>n;

	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	for(int i=0; i<n; i++){
		cin>>y[i];
	}
	a1=Manhattan(x,y,n);
	a2=Euclidean(x,y,n);
	a3=Minkowski3(x,y,n);
	a4=Chebyshev(x,y,n);

	printf("%7.6lf\n%7.6lf\n%7.6lf\n%7.6lf\n", a1, a2, a3, a4);

	//cout<<a1<<endl<<a2<<endl<<a3<<endl<<a4<<endl;
	return 0;
}
