#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>

#define rep(i, a) REP(i, 0, a)
#define REP(i, a, b) for(int i = a; i < b; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> P;
typedef std::pair<P, int> PP;
const double PI = 3.14159265358979323846;
const double esp = 1e-9;
const int infi = (int)1e+9 + 10;
const ll infll = (ll)1e+17 + 10;

int main(){
	double a, b, c;
	std::cin >> a >> b >> c;
	double theta = c * PI / 180;
	double Csize = sqrt(a * a + b * b - 2 * a * b * cos(theta));
	double h = b * sin(theta);
	double s = a * h / 2;
	printf("%.10lf %.10lf %.10lf\n", s, a + b + Csize, h);
	return 0;
}