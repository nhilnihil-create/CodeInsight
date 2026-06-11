// class point	の練習（クラスの高度な実装）
#include <iostream>
#include <iomanip>
using namespace std;



int main() {
	double r;
	double pi = 3.14159265358979323846;

	double men, syu;
	cin >> r;

	men = r * r*pi;
	syu = r * 2 * pi;
	cout <<fixed<< setprecision(6) << men << " " << syu << endl;
	return 0;
}


