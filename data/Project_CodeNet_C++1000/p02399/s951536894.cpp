#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	double a, b;
	cin >> a >> b;
	double c = 0, d = a;
	while (d >= b) {
		d = d - b;
		c++;
	}
	printf("%.10f %.10f %.10f\n", c, d, a / b);
}
