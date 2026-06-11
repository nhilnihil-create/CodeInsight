#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;


const int BIG_NUM = 1e8;

int main() {
	double a, b, h, m;

	cin >> a >> b >> h >> m;

	double th = ((h + m / 60) / 12) * M_PI * 2;
	double tm = (m / 60) * M_PI * 2;


	double td = abs(th - tm);

	cout <<fixed<< setprecision(10) << sqrt(a * a + b * b - 2 * a * b * cos(td));

}