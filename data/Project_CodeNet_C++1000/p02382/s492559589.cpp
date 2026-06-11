#include<iomanip>
#define _USE_MATH_DEFINES
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
	int n;
	double dp1 = 0, dp2 = 0, dp3 = 0, dpm = 0, d2 = 0, d3 = 0;
	double x[100];
	double y[100];
	double xy[100];
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	for (int i = 0; i < n; i++){
		cin >> y[i];
	}
	for (int i = 0; i < n; i++){
		xy[i] = sqrt((x[i] - y[i])*(x[i] - y[i]));
		d2 = d2 + pow(xy[i],(double)2);
		d3 = d3 + pow(xy[i],(double)3);
	}

	for (int i = 0; i < n; i++){
		dp1 = dp1 + xy[i];
		dp2 = sqrt(d2);
		dp3 = pow(d3,(double)1/(double)3);
		if (dpm < xy[i]){
			dpm = xy[i];
		}
	}

	cout << fixed << setprecision(6) << dp1 << endl;
	cout << fixed << setprecision(6) << dp2 << endl;
	cout << fixed << setprecision(6) << dp3 << endl;
	cout << fixed << setprecision(6) << dpm << endl;
	
	return 0;
}
