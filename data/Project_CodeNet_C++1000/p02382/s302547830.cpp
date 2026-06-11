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
	int n;
	double x[101], y[101];
	std::cin >> n;
	rep(i, n)std::cin >> x[i];
	rep(i, n)std::cin >> y[i];

	rep(i, 3){
		double ans = 0;
		rep(j, n)ans += pow(abs(x[j] - y[j]), i + 1);
		ans = pow(ans, 1.0 / (i + 1));
		printf("%.10lf\n", ans);
	}
	double ans = 0;
	rep(i, n)ans = std::max(ans, std::abs(x[i] - y[i]));
	printf("%.10lf\n", ans);
	return 0;
}