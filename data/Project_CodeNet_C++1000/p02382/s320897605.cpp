#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
inline double add(double a, double b){
	return abs(a + b) <= 1e-8 ? 0 : a + b;
}
int n;
double a[101],b[101];
double dist1(){
	double sum = 0;
	for (int i = 0; i < n; ++i){
		sum = add(sum,abs(a[i] - b[i]));
	}
	return sum;
}
double dist2(){
	double sum = 0;
	for (int i = 0; i < n; ++i){
		sum = add(sum, add(a[i], -b[i])*add(a[i], -b[i]));
	}
	return sqrt(sum);
}
double dist3(){
	double sum = 0;
	for (int i = 0; i < n; ++i){
		double tmp = abs(add(a[i], -b[i]));
		sum = add(sum, pow(tmp,3));
	}
	return cbrt(sum);
}
double dist4(){
	double MAX = abs(a[0] - b[0]);
	for (int i = 1; i < n; ++i){
		if (MAX < abs(a[i] - b[i])) MAX = abs(a[i]-b[i]);
	}
	return MAX;
}
int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	cout << fixed << setprecision(6);
	cout << dist1() << '\n';
	cout << dist2() << '\n';
	cout << dist3() << '\n';
	cout << dist4() << '\n';
}