#include <iostream>
#include <iomanip>
using namespace std;
const double PI = 3.14159265358979323846;
int main(){
	double r;
	cin>>r;
	cout << fixed << setprecision(6) << r*r*PI << " " << fixed << setprecision(6) << 2*PI*r << endl;
	return 0;
}