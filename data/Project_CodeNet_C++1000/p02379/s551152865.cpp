#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
	double x1, y1, x2, y2, tate, yoko;
	cin >> x1 >> y1 >> x2 >> y2;
	tate = y1 - y2;
	yoko = x1 - x2;
	if (tate < 0){
		tate = tate*(-1);
	}
	if (yoko < 0){
		yoko = yoko*(-1);
	}
	double answer = sqrt(tate*tate + yoko*yoko);
	cout << std::setprecision(12) << answer << endl;
	return 0;
}
