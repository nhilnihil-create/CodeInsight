#include<string>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdio>

using namespace std;


double dist1(int n,int *a,int *b){
	int i;
	double sum=0;	
	for(i=0;i<n;i++){
		sum+=fabs(a[i]-b[i]);	
		}
	return sum;
	}

double dist2(int n,int *a,int *b){
	int i;
	double sum=0;	
	for(i=0;i<n;i++){
		sum+=pow(a[i]-b[i],2);	
		}
	return sqrt(sum);
	}
	
double dist3(int n,int *a,int *b){
	int i;
	double sum=0;	
	for(i=0;i<n;i++){
		sum+=pow(fabs(a[i]-b[i]),3.0);	
		}
	return pow(sum,1.0/3);
	}

double dist4(int n,int *a,int *b){
	int i;
	double sum=0;	
	for(i=0;i<n;i++){
		if(sum<=fabs(a[i]-b[i])) sum=fabs(a[i]-b[i]);
		}
	return sum;
	}


int main(void){
	int a;
	cin >>a;
	int b[1000];
	int c[1000];
	int i;
	for (i=0;i<a;i++){
		cin >> b[i];
		}
	for(i=0;i<a;i++){
		cin >> c[i];
		}
	double dis1=dist1(a,b,c);
	double dis2=dist2(a,b,c);
	double dis3=dist3(a,b,c);
	double dis4=dist4(a,b,c);
	printf("%.6f\n%.6f\n%.6f\n%.6f\n",dis1,dis2,dis3,dis4);
	return 0;
	}