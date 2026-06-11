#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    const double pi=3.14159265358979323846;
	double r;
	cin>>r;
	cout<<fixed<<setprecision(8)<<pi*r*r<<" "<<2*pi*r<<endl;
	return 0;
}
