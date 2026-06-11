#include <iostream>
using namespace std;
int main(){
	long long a;
	double b;
	scanf("%lld %lf",&a,&b);
	b=b+0.00000001;
	long long c = b*100;
	long long d = c*a/100;
	cout << d ;
	return 0;
}