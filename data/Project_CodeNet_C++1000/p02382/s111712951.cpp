#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	int n;cin>>n;
	double x[100],y[100],a[100];
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=0;i<n;i++)cin>>y[i];
	for(int i=0;i<n;i++)a[i]=abs(x[i]-y[i]);
	double p1,p2,p3,p4;p1=p2=p3=p4=0.0;
	for(int i=0;i<n;i++)p1+=a[i];
	for(int i=0;i<n;i++)p2+=a[i]*a[i];
	p2=sqrt(p2);
	for(int i=0;i<n;i++)p3+=a[i]*a[i]*a[i];
	p3=cbrt(p3);
	for(int i=0;i<n;i++)p4=p4<a[i]?a[i]:p4;
	cout<<fixed<<setprecision(5)<<p1<<endl<<p2<<endl<<p3<<endl<<p4<<endl;
	return 0;
}