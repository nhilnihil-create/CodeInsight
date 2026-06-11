#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	double n,x[100],y[100],d1sum,d2sum,d3sum,dinf;
	d1sum = 0;
	d2sum = 0;
	d3sum = 0;
	cin >> n;
	for(int i = 0;i < n ; i++){
		cin >> x[i];
	}
	for(int i = 0;i < n ; i++){
		cin >> y[i];
		d1sum +=fabs(x[i]-y[i]);
		d2sum +=pow(fabs(x[i]-y[i]),2);
		d3sum +=pow(fabs(x[i]-y[i]),3);
		dinf = max(fabs(x[i]-y[i]),dinf);
	}
	cout << fixed << setprecision(6) << d1sum << endl << pow(d2sum,1.0/2.0) << endl << pow(d3sum,1.0/3.0) << endl << dinf << endl;
    return 0;
}