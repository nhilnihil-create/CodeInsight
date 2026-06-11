#include <iostream>

#define _USE_MATH_DEFINES

#include <cmath>

using namespace std;

class point{
public:
	double x, y;
	int set_x();
	int set_y();
};

int point::set_x()
{
	cin >> x;
	return 0;
}
int point::set_y()
{
	cin >> y;
	return 0;
}

int main()
{
	point P[1000] = {};
	int n;
	int i;
	double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	double max = 0;

	cin >> n;

	for (i = 0; i < n; i++){
		P[i].set_x();
	}

	for (i = 0; i < n; i++){
		P[i].set_y();
	}

	for (i = 0; i < n; i++){
		d1 += abs(P[i].x - P[i].y);
		d2 += abs(P[i].x - P[i].y) * abs(P[i].x - P[i].y);
		d3 += pow(abs(P[i].x - P[i].y), 3);
		if (max < abs(P[i].x - P[i].y))
			max = abs(P[i].x - P[i].y);
	}

	d2 = sqrt(d2);
	d3 = pow(d3, 1.0 / 3.0);
	d4 = max;

	cout << fixed << d1 << endl << d2 << endl << d3 << endl << d4 << endl;

	return 0;
}