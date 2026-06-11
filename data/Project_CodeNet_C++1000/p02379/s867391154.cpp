#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
inline double add(double a, double b){
	return abs(a + b) <= 1e-8 ? 0 : a + b;
}
int main(){
	double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	double dist = sqrt(add(add(x2,-x1)*add(x2, -x1), add(y2, -y1)*add(y2, -y1)));
	cout << fixed << setprecision(8) << dist << '\n';
}