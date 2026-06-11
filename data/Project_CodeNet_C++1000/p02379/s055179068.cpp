#include<iostream>
#include<iomanip>
#include<math.h>

//関数の宣言
void xSwap(double& x1, double& x2);
void ySwap(double& y1, double& y2);

int main()
{
	double x1;
	double x2;
	double y1;
	double y2;

	std::cin >> x1 >> y1 >> x2 >> y2;

	xSwap(x1, x2);
	ySwap(y1, y2);

	double base;
	double height;

	base = x1 - x2;
	height = y1 - y2;

	double hypotenuse;
	double ans;

	hypotenuse = base*base + height*height;
	ans = sqrt(hypotenuse);

	std::cout << std::fixed << std::setprecision(20) << ans << std::endl;

	return 0;
}

//関数の定義
void xSwap(double& x1, double& x2){
	if (x1 < x2){
		double tmp;

		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
}

void ySwap(double& y1, double& y2){
	if (y1 < y2){
		double tmp;

		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
}
