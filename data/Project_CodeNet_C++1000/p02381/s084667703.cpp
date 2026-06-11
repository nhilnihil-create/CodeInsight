#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
inline double add(double a, double b){
	return abs(a + b) <= 1e-8 ? 0 : a + b;
}
double a[1001];
int main(){
	while (true){
		int n; cin >> n; if (!n) break;
		for (int i = 0; i < n; ++i) cin >> a[i];
		double s = 0;
		for (int i = 0; i < n; ++i) s += a[i];
		s /= n;
		double v = 0;
		for (int i = 0; i < n; ++i) v += add(a[i], - s)*add(a[i],-s);
		v /= n;
		cout << fixed << setprecision(8) << sqrt(v) << '\n';
	}
}