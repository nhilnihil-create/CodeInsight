#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int x, y, a = 0, b = 0;
	double c = 0;
	cin>>x>>y;
	a = x / y;
	b = x % y;
	c = double(x) / double(y);
	cout<<a<<" "<<b<<" "<<setprecision(5)<<fixed<<c<<endl;
return 0;
}