#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main() {
	string x, y;
	int num, xnum = 0, ynum = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> x >> y;
		if (x[0] - 'a' > y[0] - 'a') {
			xnum += 3;
		}
		else if (x[0] - 'a' < y[0] - 'a') {
			ynum += 3;
		}else {
			for (int j = 0; j < x.size(); j++) {
				if (x[j] - 'a' > y[j] - 'a') {
					xnum += 3;
					break;
				}
				else if (x[j] - 'a' < y[j] - 'a') {
					ynum += 3;
					break;
				}
				if (x.size() - 1 == j) {
					if (x.size() > y.size())xnum += 3;
					if (x.size() < y.size())ynum += 3;
					if (x.size() == y.size()) {
						xnum += 1;
						ynum += 1;
					}
				}
			}
		}
	}
	cout << xnum << " "<< ynum << endl;

	return 0;
}