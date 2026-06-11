/*
 * StandardDeviation.cpp
 *
 *  Created on: 2014/07/21
 *      Author: WanWan1985
 */
#include <iostream>
#include <vector>
#include <iomanip>	// for setprecision
#include <cmath>	// for pow
#include <numeric>	// for accumulate
using namespace std;

int main(void) {

	vector<vector<int> > vecData;
	while(1) {
		int iStudentNum = 0;
		cin >> iStudentNum;
		if (0 == iStudentNum) {
			break;
		}

		vector<int> vecScore;
		for (int i = 0; i < iStudentNum; i++) {
			int iScore = 0;
			cin >> iScore;
			vecScore.push_back(iScore);
		}

		vecData.push_back(vecScore);
	}

	for (unsigned int i = 0; i < vecData.size(); i++) {
		vector<int> vecDataSet = vecData.at(i);
		// 平均値
		double dAverageScore = accumulate(vecDataSet.begin(), vecDataSet.end(), 0.0) / vecDataSet.size();

		// 分散
		double dSum = 0.0;
		for (unsigned int j = 0; j < vecDataSet.size(); j++) {
			dSum += pow(vecDataSet.at(j) - dAverageScore, 2);
		}
		double dVariance = dSum / vecDataSet.size();

		cout << fixed << setprecision(8) << sqrt(dVariance) << endl;
	}
	return 0;
}