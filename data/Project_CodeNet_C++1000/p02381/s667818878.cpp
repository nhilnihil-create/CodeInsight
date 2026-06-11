
#include<iostream>
#include<string>
#include<algorithm>
#define _USE_MATH_DEFINES
#include<math.h>
#include<iomanip>

using namespace std;

int main() {
	double a =0, ave, s = 0;
	int n, i;
	int box[1000] = {};
	while(1){
	cin >> n;
	if (n == 0) { break; }
	for (i = 0; i < n; i++) {
		cin >> box[i];
	}
	for (i = 0; i < n; i++) {
		a += box[i];
	}
	ave = a / n;
	for (i = 0; i < n; i++) {
		s += (box[i] - ave) * (box[i] - ave);
	}
	
	cout << fixed << setprecision(6)<<sqrt(s/n) << endl;
	a = 0;
	s = 0;
	}
	cout << endl;

	return 0;
}

