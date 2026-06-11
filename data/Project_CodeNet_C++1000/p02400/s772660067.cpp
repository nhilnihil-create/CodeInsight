#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
    double r;
	cin>>r;
	double a,b;
	a=r*r*3.14159265358979;
	b=r*2*3.14159265358979;
	cout<<fixed<<setprecision(10)<<a<<endl;
	cout<<fixed<<setprecision(10)<<b<<endl;
	return 0;
}