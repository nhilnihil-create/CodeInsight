#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int d,r;
	double a,b,f,w;
	f=0.0;
	a=0.0;
	b=0.0;
	w=0.00000;
	cin>>a>>b;
	d=a/b;
	r=(int)a%(int)b;
	f=(double)a/(double)b;

	cout<<d<<' '<<r<<' '<<fixed<<setprecision(5)<<f<<endl;
	
}
