#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
#ifdef CIN
	ifstream cin("input.txt");
	// ofstream cout("output.txt");
	freopen("output.txt", "w", stdout);
#endif

	double x;
	cin >> x;

	double a, b;

	a = x * x * 3.1415926535897932384626433832795;
	b = 2 * x * 3.1415926535897932384626433832795;

	printf("%lf %lf\n", a, b);

	return 0;
}