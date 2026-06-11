#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	double x=fabs(x2-x1);
	double y=fabs(y2-y1);
	cout<<fixed<<setprecision(4)<<sqrt(x*x+y*y)<<endl;
	return 0;
}