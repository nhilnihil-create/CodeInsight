#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int d,r,g,h;
	double f,a,b;
	cin>>a>>b;
	g=a;
	h=b;
	d=a/b;
	r=g%h;
	f=a/b;
	
	cout<<d<<" "<<r<<" ";
	cout<<fixed<<setprecision(5)<<f<<endl;
	return 0;
}