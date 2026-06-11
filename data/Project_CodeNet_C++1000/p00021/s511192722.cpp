#include <iostream>
#include <complex>
using namespace std;

int main()
{
	int n;
	cin>>n;
	complex<double> a,b,c,d;
	while(n--)
	{
		cin>>a.real()>>a.imag()>>b.real()>>b.imag()>>c.real()>>c.imag()>>d.real()>>d.imag();
		a=a-b;
		c=c-d;

		cout<<(a.real()*c.imag()-a.imag()*c.real()==0?"YES":"NO")<<endl;
	}
	return 0;
}