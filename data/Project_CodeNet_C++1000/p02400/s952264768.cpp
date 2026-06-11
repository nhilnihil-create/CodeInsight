#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main(){
	double r,S,C;
	cin>>r;
	S=r*r*M_PI;
	C=r*2*M_PI;
	cout<<fixed<<setprecision(6)<<S<<" "<<C<<endl;
	return 0;
}