#include <iostream>
#include <iomanip>
#include <cmath>
/*a, b とその間の角 C から、その三角形の面積 S、周の長さ L, a を底辺としたときの高さ h を求めるプログラムを作成して下さい。*/
using namespace std;

int main(){
	double pi = 3.141592653589793;
	//(xpi)/180
	double a, b, C;
	cin >> a >> b >> C;
	double rad =  (C * pi) / 180;
	cout << setprecision(15);
	cout << (a * sin(rad) * b) / 2 << '\n';
	double c = sqrt(a * a + b * b - (2 * a * b * cos(rad)));
	cout << a + b + c << '\n';
	//sinB
	double sinB = b * sin(rad) / c;
	cout <<  c * sinB << endl;
}

