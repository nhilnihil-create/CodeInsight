#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;

int main(){
	double m=0,U,u=0,s,c=0,n,x[110],y[110];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	for(int i=0;i<n;i++){
		cin>>y[i];
	}
	for(int i=0;i<n;i++){
		m+=fabs(x[i]-y[i]);
	}
	cout<<fixed<<setprecision(6)<<m<<endl;
	for(int i=0;i<n;i++){
		u+=(x[i]-y[i])*(x[i]-y[i]);
	}
	U=sqrt(u);
	cout<<fixed<<setprecision(6)<<U<<endl;
	u=0;
	for(int i=0;i<n;i++){
		u+=(x[i]-y[i])*(x[i]-y[i])*fabs((x[i]-y[i]));
	}
	s=pow(u,1.0/3.0);
	cout<<fixed<<setprecision(6)<<s<<endl;
	c=fabs(x[0]-y[0]);
	for(int i=0;i<n-1;i++){
		if(c<fabs(x[i+1]-y[i+1]))c=fabs(x[i+1]-y[i+1]);
	}
	cout<<fixed<<setprecision(6)<<c<<endl;
	return 0;
}