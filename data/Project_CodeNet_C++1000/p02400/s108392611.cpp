#include<iostream>
#include <iomanip>

#define PI 3.14159265359	

using namespace std;

int main(){
	double r;
	cin >> r;
	cout << fixed << setprecision(10) << PI * r * r << " " << 2 * PI * r;

}