#include <iostream>

using namespace std;

int main() {
	long int a, b;
	cin >> a >> b;
	cout << a / b << " ";
	cout << a % b << " ";
	long double ax = a;
	long double bx = b;
	cout << fixed << ax / bx << endl;
}