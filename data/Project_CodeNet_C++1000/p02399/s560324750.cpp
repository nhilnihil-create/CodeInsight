#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	int a, b;
	cin >> a >> b;
	double c = 1.0000 * a / b;
	cout << a / b << " " << a % b << " " << fixed << c << endl;

return 0;
}