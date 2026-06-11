#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){

	double pai,r;
	double men,syu;
//	pai=3.1415926538979;
	pai=M_PI;
	cin>>r;
	men=r*r*pai;
	syu=r*pai*2;
	cout<<fixed
		<<setprecision(6)
		<<men
		<<" "
	//	<<fixed
	//	<<setprecision(6)
		<<syu
		<<endl;

	return 0;
}