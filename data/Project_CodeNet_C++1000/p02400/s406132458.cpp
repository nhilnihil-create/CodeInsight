/*
 * Circle.cpp
 *
 *  Created on: 2014/07/21
 *      Author: WanWan1985
 */
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(void) {
	double dr = 0.0;
	cin >> dr;

	cout << fixed << setprecision(8) <<  pow(dr, 2.0) * M_PI << " " << 2 * M_PI * dr << endl;

	return 0;
}