#include <iostream>
#include <math.h>
using namespace std;
int main(void){
	cout.precision(11);
	double  a,b,x;
	cin >>a>>b>>x;
	if(x<=a*a*b/2){
		cout << 90-180*atan((2*x)/(a*b*b))/acos(-1.0) <<endl;
	}
	else cout << 90-180*atan((a*a)/(2*a*b-2*x/a))/acos(-1.0)<<endl;
	return 0;
}