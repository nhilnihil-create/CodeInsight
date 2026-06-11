#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

double r;

int main(){
	cin.tie(0);
	
	cin>>r;
	
	cout<<fixed<<setprecision(5)<<r*r*M_PI<<' '<<2*r*M_PI<<endl;

	return 0;
}

