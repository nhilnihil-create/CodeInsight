#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double r;
	double pai = 3.141592653589793;
	cin >> r;
	cout << fixed << setprecision(6) << r * r * pai << " ";
	cout << 2 * r * pai << endl;
	return 0;
}