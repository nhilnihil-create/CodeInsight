/*
 * AB_Problem.cpp
 *
 *  Created on: 2014/07/21
 *      Author: WanWan1985
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {

	int a, b = 0;
	cin >> a >> b;

	int iResult1 = a / b;
	int iResult2 = a % b;
	double dResult3 = (double)a / (double)b;

	printf("%d %d %.8lf\n", iResult1, iResult2, dResult3);

	return 0;
}