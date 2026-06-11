/*
 * Distance2.cpp
 *
 *  Created on: 2014/07/21
 *      Author: WanWan1985
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(void) {

	int n = 0;
	cin >> n;

	vector<int> vecX, vecY;
	for (unsigned int i = 0; i < n; i++) {
		int iX = 0;
		cin >> iX;
		vecX.push_back(iX);
	}

	for (unsigned int i = 0; i < n; i++) {
		int iY = 0;
		cin >> iY;
		vecY.push_back(iY);
	}

	double dDistance1 	= 0.0;	// p = 1
	double dDistance2 	= 0.0;	// p = 2
	double dDistance3 	= 0.0;	// p = 3
	double dDistanceInf = 0.0;	// p = infinity
	vector<double> vecInf;
	for (unsigned int j = 0; j < vecX.size(); j++) {
		dDistance1 += fabs(vecX.at(j) - vecY.at(j));
		dDistance2 += pow(fabs(vecX.at(j) - vecY.at(j)), 2.0);
		dDistance3 += pow(fabs(vecX.at(j) - vecY.at(j)), 3.0);
		vecInf.push_back(fabs(vecX.at(j) - vecY.at(j)));
	}
	dDistance2		= sqrt(dDistance2);
	dDistance3 		= cbrt(dDistance3);
	dDistanceInf 	= *max_element(vecInf.begin(), vecInf.end());

	cout << fixed << setprecision(6) << dDistance1 << endl;
	cout << fixed << setprecision(6) << dDistance2 << endl;
	cout << fixed << setprecision(6) << dDistance3 << endl;
	cout << fixed << setprecision(6) << dDistanceInf << endl;

	return 0;
}