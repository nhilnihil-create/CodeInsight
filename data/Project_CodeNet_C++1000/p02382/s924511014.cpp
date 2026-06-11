//#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <functional>
#include <cmath>

using namespace std;

int main(){

	int n,buf,dif;
	double D1 = 0, D2 = 0, D3 = 0, D4 = 0;

	vector <int> x, y;

	cin >> n;

	for(int i=0; i< n; i++){
		cin >> buf;
		x.push_back(buf);
	}
	for (int i = 0; i< n; i++){
		cin >> buf;
		y.push_back(buf);
	}

	for (int i = 0; i < n; i++){
		dif = abs(x[i] - y[i]);
		D1 += dif;
		D2 += pow(dif, 2);
		D3 += pow(dif, 3);
		if (dif > D4) D4 = dif;
	}
	D2 = pow(D2, 1.0 / 2.0);
	D3 = pow(D3, 1.0 / 3.0);

	cout << fixed << setprecision(6);
	cout << D1 << endl;
	cout << D2 << endl;
	cout << D3 << endl;
	cout << D4 << endl;


	return 0;
}