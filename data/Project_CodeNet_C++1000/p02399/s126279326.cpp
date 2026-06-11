#include<iostream>
#include <iomanip>

using namespace std;

int main(){
	double a, b;
	cin >> a >> b;
	cout << (int)a / (int)b << " " << (int)a % (int)b << " " << fixed << setprecision(10) << a / b << endl;

}