#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {

	int a, b;
	cin >> a >> b;

	int d, r;
	double f;
	d = a / b;
	r = a % b;
	//f = (double)a / double(b);
	f = static_cast<double>(a) / static_cast<double>(b);

	cout << d << " " << r << " ";
	printf("%.8f\n",f);

	return 0;
}