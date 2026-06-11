#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
	double a,b,C,S,L,h;
	cin>>a>>b>>C;
	C=C*M_PI/180;
	S=a*b*sin(C)/2;
	L=a+b+sqrt(a*a+b*b-2*a*b*cos(C));
	h=b*sin(C);
	cout<<fixed<<setprecision(4)<<S<<endl;
	cout<<fixed<<setprecision(4)<<L<<endl;
	cout<<fixed<<setprecision(4)<<h<<endl;
	return 0;
}