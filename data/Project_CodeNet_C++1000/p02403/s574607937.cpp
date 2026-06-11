/*
 * PrintARectangle.cpp
 *
 *  Created on: 2014/07/21
 *      Author: WanWan1985
 */
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int a_H, a_W;
}DataSet;

int main(void) {

	vector<DataSet> vecDataSet;
	while (1) {
		DataSet data;
		int H, W = 0;
		cin >> H >> W;
		if ((0 == H) && (0 == W)) {
			break;
		}
		data.a_H = H;
		data.a_W = W;
		vecDataSet.push_back(data);
	}

	for (unsigned int i = 0; i < vecDataSet.size(); i++) {
		DataSet data = vecDataSet.at(i);
		for (int i = 0; i < data.a_H; i++) {
			for (int j = 0; j < data.a_W; j++) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}