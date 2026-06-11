#include <iostream>
#include <iomanip>
#define pi 3.14159265358979323846
using namespace std;

int main()
{
	double r,l,s;
	cin>>r;
	l = 2*pi*r;
	s = pi*r*r;
	cout<<setprecision(9)<<fixed<<s<<" "<<l<<endl;
	return 0;
}
 
