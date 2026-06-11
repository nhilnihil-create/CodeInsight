#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	double point[2][4097];
	point[0][0] = 0; point[1][0] = 0; point[0][4096] = 100; point[1][4096] = 0;
	double l = 100; double root3 = sqrt(3.0); double gosa = 0.0001;

	for(int i = 0; i < n; i++){
		l = 100 / pow(3.0,i + 1);
		int step = pow(4.0,6-i);
		int step4 = step / 4;
		double x,y;
		for(int j = 0; j < 4096; j += step){
			point[0][j + step4] = point[0][j] / 3 * 2 + point[0][j + step] / 3;
			point[1][j + step4] = point[1][j] / 3 * 2 + point[1][j + step] / 3;
			point[0][j + step4 * 3] = point[0][j] / 3 + point[0][j + step] / 3 * 2;
			point[1][j + step4 * 3] = point[1][j] / 3 + point[1][j + step] / 3 * 2;


			x = point[0][j + step4] - point[0][j];
			y = point[1][j + step4] - point[1][j];

			point[0][j + step4 * 2] = point[0][j + step4] + x / 2 - y / 2 * root3;
			point[1][j + step4 * 2] = point[1][j + step4] + x / 2 * root3 + y / 2;
		}
	}

	int step = pow(4.0, 6 - n);

	for(int i = 0; i < 4097; i += step)
		cout << fixed << setprecision(8) << point[0][i] << " " << point[1][i] << endl;
}