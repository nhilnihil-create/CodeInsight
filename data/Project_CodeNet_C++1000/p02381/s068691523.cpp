#include <iostream>

#define _USE_MATH_DEFINES

#include <cmath>

using namespace std;

int main()
{
	int n;
	int i;
	double sd;
	double sum, point[1000] = {};
	double ave = 0;

	while (1){
		cin >> n;
		
		if (n == 0)
			break;

		sd = 0;
		sum = 0;
		for (i = 0; i < n; i++){
			cin >> point[i];
			sum += point[i];
		}
		ave = sum / n;
		for (i = 0; i < n; i++){
			sd += (point[i] - ave)*(point[i] - ave);
		}
		sd = sqrt(sd / n);

		cout << fixed << sd << endl;

	}

	return 0;
}