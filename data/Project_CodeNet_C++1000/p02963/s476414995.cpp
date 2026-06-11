#include <iostream>
using namespace std;

int main() {
	long S;
	cin >> S;
	long X1 = (S + 999999999) / 1000000000, X2 = X1 * 1000000000 - S;
	cout << X1 << " 1 " << X2 << " 1000000000 0 0";
}