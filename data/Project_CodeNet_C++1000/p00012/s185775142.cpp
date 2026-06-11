#include<iostream>
#include<complex>
using namespace std;
typedef complex<double> p;

int main()
{
	p a,b,c,d;
	while(cin>>a.real()>>a.imag()>>b.real()>>b.imag()>>c.real()>>c.imag()>>d.real()>>d.imag())
	{
		a=a-d; 
		b=b-d; 
		c=c-d;

		double ab=a.real()*b.imag()-a.imag()*b.real();
		double bc=b.real()*c.imag()-b.imag()*c.real();
		double ca=c.real()*a.imag()-c.imag()*a.real();

		if(ab<0&&bc<0&&ca<0) cout<<"YES"<<endl;
		else if(ab>0&&bc>0&&ca>0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}