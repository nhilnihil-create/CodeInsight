# include<iostream>
#include <iomanip>

using namespace std;
int main() {
	int a = 0;
	int b = 0;
	double da = 0;
	double db = 0;
	cin >> a >> b;
	da = (double)a;
	db = (double)b;
	cout << fixed;
	cout << a / b << " " << a%b << " " <<  setprecision(1000) << da/db << endl;
	return 0;
}