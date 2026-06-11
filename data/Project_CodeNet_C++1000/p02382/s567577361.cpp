#include<iostream>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(){
	double x[1000],y[1000],D1=0,D2=0,D3=0,D4=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=0;i<n;i++)cin>>y[i];
	for(int i=0;i<n;i++){
		D1+=fabs(x[i]-y[i]);
		D2+=(x[i]-y[i])*(x[i]-y[i]);
		D3+=fabs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
		D4=max(fabs(x[i]-y[i]),D4);
	}
	cout<<fixed<<setprecision(5)<<D1<<endl;
	cout<<fixed<<setprecision(5)<<sqrt(D2)<<endl;
	cout<<fixed<<setprecision(5)<<pow(D3,1.0/3.0)<<endl;
	cout<<fixed<<setprecision(5)<<D4<<endl;
}
