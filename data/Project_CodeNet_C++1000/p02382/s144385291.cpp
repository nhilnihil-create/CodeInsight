#include<iostream>
#include<cmath>
#include <cstdlib> 
#include<iomanip>
using namespace std;
int main(){
	int n;
	int x[1000]={0};
	int y[1000]={0};
	long double d=0;
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i];
	for(int i=0;i<n;i++)
		cin>>y[i];
		
	for(int i=0;i<n;i++)
		d+=abs(x[i]-y[i]);
	cout<<fixed<<setprecision(6)<<d<<endl;
	
	d=0;
	for(int i=0;i<n;i++)
		d+=pow(abs(x[i]-y[i]),2);
	cout<<fixed<<setprecision(6)<<sqrt(d)<<endl;
	
	d=0;
	for(int i=0;i<n;i++)
		d+=pow(abs(x[i]-y[i]),3);
	cout<<fixed<<setprecision(6)<<pow(d,1.0/3.0)<<endl;
	
	d=0;
	
	for(int i=0;i<n;i++){
		if(d<=abs(x[i]-y[i]))
			d=abs(x[i]-y[i]);
	}
	cout<<fixed<<setprecision(6)<<d<<endl;
}