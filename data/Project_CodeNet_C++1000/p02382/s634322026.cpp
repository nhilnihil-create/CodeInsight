#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, i, d1, d4;
	cin >> n;
	int x[n], y;
	double d2, d3;
	d1 = 0;
	d2 = 0;
	d3 = 0;
	d4 = 0;
	for (i = 0; i < n; ++i){
		cin >> x[i];
	}
	for (i = 0; i < n; ++i){
		cin >> y;
		d1 += abs(x[i]-y);
		d2 += (x[i]-y)*(x[i]-y);
		d3 += abs((x[i]-y)*(x[i]-y)*(x[i]-y));
		d4 = max(d4,abs(x[i]-y));
	}
	d2 = sqrt(d2);
	d3 = cbrt(d3);
	printf("%d\n%.8lf\n%.8lf\n%d\n", d1, d2, d3, d4);
	return 0;
}