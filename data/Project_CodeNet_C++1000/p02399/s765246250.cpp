#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int a, b;
	cin >> a;
	cin >> b;
	double a2 = a, b2 = b;
	cout << a / b << endl << a%b << endl;
	cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << setprecision(10) << a2 / b2 << endl;
	return 0;
}