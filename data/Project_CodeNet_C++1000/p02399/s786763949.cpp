#include <cstdio>
#include <iostream>
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout << a / b << " " << a % b << " ";
	double d;
	d = (double) a / b;
	printf("%.10lf\n", d);
	return 0;
}