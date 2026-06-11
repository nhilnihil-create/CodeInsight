/*
 * Triangle.cpp
 *
 *  Created on: 2014/07/21
 *      Author: WanWan1985
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {

	int a, b, theta;
	cin >> a >> b >> theta;

	// 面積
	double dArea = 0.5 * (double)a * (double)b * sin(theta * M_PI / 180);

	// 周の長さ
	double dLength = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(theta * M_PI / 180));

	// 高さ
	double dHigh = 2.0 * dArea / a;

	cout << fixed << setprecision(8) << dArea << endl;
	cout << fixed << setprecision(8) << dLength << endl;
	cout << fixed << setprecision(8) << dHigh << endl;

	return 0;
}