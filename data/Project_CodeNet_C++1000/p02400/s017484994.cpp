#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	double a; cin >> a;
	double pi = 3.141592653589793238462643383279502884197169;
	printf("%.10f %.10f\n", a * a * pi, a * 2 * pi);
	cin >> a;
}
