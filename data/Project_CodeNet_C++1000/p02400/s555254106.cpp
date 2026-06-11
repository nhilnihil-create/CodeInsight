#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double p=3.141592653589,r,x,y;
	cin>>r;
	x=p*r*r;
	y=2*p*r;
	cout<<fixed<<setprecision(6)<<x<<" "<<y<<endl;
	return 0;
}