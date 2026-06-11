#include<iostream>
#include<cmath>
using namespace std;


int main() {
	unsigned long long a, b;
	cin >> a >> b;
	if (a == 1 || b == 1) {
		cout << 1 <<endl;
	}
	else cout << (a*b+1) / 2 <<endl;
	return 0;
}