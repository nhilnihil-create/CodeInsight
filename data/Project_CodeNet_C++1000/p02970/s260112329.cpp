#include <iostream>
using namespace std;
int main() {
	int n, d;
	cin >> n >> d;
	if (n % (d * 2 + 1) == 0)
		cout << (n / (d * 2 + 1));
	else
		cout << (n / (d * 2 + 1)) + 1;
}