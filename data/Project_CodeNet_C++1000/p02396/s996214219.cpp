#include <iostream>
using namespace std;
int main () {
	int a;
	int b = 1;
	cin >> a;
	while (a > 0) {
		cout << "Case" << " " << b << ":" << " " << a << endl;
		b = b+1; 
		cin >> a;
	}
	return 0;
	}
