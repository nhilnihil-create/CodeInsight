#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
double f(int x[],int y[],int n,int p);
int main(){
	int n;
	cin>>n;
	int v[2][n];
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			cin>>v[i][j];	
		}
	}
	for(int i=1;i<=3;i++){
		cout<<fixed<<setprecision(5)<<f(v[0],v[1],n,i)<<endl;
	}
	cout<<fixed<<setprecision(5)<<f(v[0],v[1],n,INT_MAX)<<endl;
	return 0;
}

double f(int x[],int y[],int n,int p){
	double D=0;
	if(p!=INT_MAX){
		for(int i=0;i<n;i++){
			D+=pow(abs(x[i]-y[i]),p);
		}
		D=pow(D,1.0/p);
	}else{
		for(int i=0;i<n;i++){
			D=abs(x[i]-y[i])>D?abs(x[i]-y[i]):D;
		}
	}
	return D;
}