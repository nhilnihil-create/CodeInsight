#include <iostream>
#include <algorithm>
#include <complex>
#include <iomanip>
/*２点 P1(x1, y1), P2(x2, y2) の距離を求めるプログラムを作成せよ。
 */
using namespace std;

int main(){
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << setprecision(100) << sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

