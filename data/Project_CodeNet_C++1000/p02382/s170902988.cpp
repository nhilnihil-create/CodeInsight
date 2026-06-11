#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin >> n;
	double dist, x2, x[n];
	double d1 = 0, d2 = 0, d3 = 0, dinf = 0;
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		cin >> dist;
		dist = abs(x[i] - dist);
		x2 = dist*dist;
		d1 += dist;
		d2 += x2;
		d3 += x2*dist;
		if(dist > dinf) dinf = dist;
	}

	cout << fixed << setprecision(5)
			<< d1 << endl
			<< sqrt(d2) << endl
			<< cbrt(d3) << endl
			<< dinf << endl;
	return 0;
}