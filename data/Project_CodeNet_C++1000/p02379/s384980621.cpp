#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	printf("%.10lf\n", sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0)));
	return 0;
}