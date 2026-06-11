#include <iostream>
using namespace std;

int gcd(int x, int y){
	if (y != 0)	gcd(y, x%y);
	else return x;
}

int main(void){
	int x, y;

	cin >> x >> y;

	cout << gcd(x, y) << "\n";

	return 0;
}