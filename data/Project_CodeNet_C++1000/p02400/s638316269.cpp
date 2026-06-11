#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.141592653589


int main(){
	double r;
	double area, around;

	cin >> r;

	area = r * r * PI;

	around = 2 * r * PI;

	cout << fixed << setprecision(5) << area << " " << around << endl;

}