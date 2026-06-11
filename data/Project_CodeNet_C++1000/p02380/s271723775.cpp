#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	double pi=M_PI,c,S,L,h,hen;
	double a,b;
	cin>>a>>b>>c;
	double rad=c/180*pi;
	//cout<<sin(rad)<<endl;
	S=1/2.0*a*b*sin(rad);
	h=2*S/a;
	hen=pow(a*a+b*b-2*a*b*cos(rad),1.0/2);
	L=hen+a+b;
	cout<<setprecision(10)<<S<<endl<<L<<endl<<h<<endl;
	return 0;
}
