
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <list>
#define _USE_MATH_DEFINES
#include <math.h>
//#include <cmath>
#include <random>
#include <algorithm>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

using std::vector;
using std::list;
using std::string;
using std::pair;
using std::tuple;



void func();

int main() {
	func();
}

bool henkaku3(tuple<long double, long double, long double> v1, tuple<long double, long double, long double> v2) {
	long double t1 = std::get<0>(v1);
	long double t2 = std::get<0>(v2);
	return t1 < t2;
}

void func()
{
	int N;
	vector<tuple<long double, long double, long double> > V;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x;
		cin >> y;
		if (x == 0 && y == 0) {
			continue;
		}
		else {
			//pair<long double, long double> v((long double)x, (long double)y);
			long double t = atan2l(y,x);
			V.push_back(std::make_tuple(t, x, y));
		}
	}
	N = (int)V.size();
	for (int i = 0; i < N; ++i) {
		//cerr << std::get<0>(V[i]) << ", " << std::get<1>(V[i]) << ", " << std::get<2>(V[i]) << endl;
	}
	std::sort(V.begin(), V.end(), henkaku3);
	for (int i = 0; i < N; ++i) {
		//cerr << std::get<0>(V[i]) << ", " << std::get<1>(V[i]) << ", " << std::get<2>(V[i]) << endl;
	}

	long double r_max=0;
	for (int i = 0; i < N; ++i) {
		long double t0 = std::get<0>(V[i]);

		long double x0 = 0.0;
		long double y0 = 0.0;
		long double x1 = 0.0;
		long double y1 = 0.0;
		for (int j = 0; j < N; ++j) {
			long double t1 = std::get<0>(V[j]);
			long double t = t1 - t0;
			if (t < 0) {
				t +=  2 * M_PI;
			}
			if (t > 2 * M_PI) {
				t -= 2 * M_PI;
			}
			if (t >= 0 && t < M_PI) {
				x0 += std::get<1>(V[j]);
				y0 += std::get<2>(V[j]);
			}
			if (t > M_PI && t <= 2*M_PI) {
				x1 += std::get<1>(V[j]);
				y1 += std::get<2>(V[j]);
			}
		}
		long double r0 = sqrt(x0 * x0 + y0 * y0);
		long double r1 = sqrt(x1 * x1 + y1 * y1);
		r0 = std::max(r0, r1);
		r_max = std::max(r0,r_max);
	}
	cout <<std::fixed<<std::setprecision(50) <<r_max << endl;

}
