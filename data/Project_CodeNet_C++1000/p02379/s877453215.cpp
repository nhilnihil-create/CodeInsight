/*
 * Distance.cpp
 *
 *  Created on: 2014/07/21
 *      Author: WanWan1985
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {

	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	double dDistance = 0.0;
	dDistance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	cout << fixed << setprecision(8) << dDistance << endl;

	return 0;
}