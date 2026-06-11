#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double r;
	cin >> r;
	cout << fixed << setprecision(10) << 3.141592653589*r*r << " " << 2*3.141592653589*r << endl;
}