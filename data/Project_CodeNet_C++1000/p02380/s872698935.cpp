#include <bits/stdc++.h>
using namespace std;

int main(void){
	int a,b,c;
	cin>>a>>b>>c;
	double C = 3.1415926535*c/180;
	double cl = sqrt(a*a+b*b-2*b*a*cos(C));
	double S = a*b*sin(C)/2;
	cout <<setprecision(10)<<S<<endl;
	cout <<setprecision(10)<<a+b+cl<<endl;
	cout << setprecision(10)<<2*S/a<<endl;
}
