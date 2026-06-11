#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int main(){
	cout<<fixed<<setprecision(6);
	double o=acos(-1.0);
	double r;
	cin>>r;
	cout<<r*r*o<<" "<<r*2*o<<endl;

	return 0;
}