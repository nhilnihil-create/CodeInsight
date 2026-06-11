#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double a,b;
	cin >> a >> b;
	int c=a, d=b;
	cout << c/d << " " << c%d << " " << fixed << setprecision(5) << a/b << endl;
	return 0;
}