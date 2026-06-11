#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	double r;
	cin >> r;

	double men = r * r * 3.141592653589;
	double shu = r * 2 * 3.141592653589;
	cout << fixed << men << " " << fixed << shu << endl;

return 0;
}