#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<double> X(n);
	double y, sum=0.0, sum2=0.0, sum3=0.0, xymax=0.0, tmp;

	for(auto &x : X) cin >> x;
	for(auto &x : X) { 
		cin >> y; 
		x = fabs(x-y); 
		xymax = (xymax>x) ? xymax : x;
		sum += (tmp=x); 
		sum2 += (tmp*=x);
		sum3 += (tmp*=x);
	}

	cout << fixed << setprecision(5);
	cout << sum << '\n' << sqrt(sum2) << '\n' << pow(sum3, 1.0/3.0) << '\n' << xymax << endl;

	return 0;
}

