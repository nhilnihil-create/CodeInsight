#include<iostream>
using namespace std;
int main() {
	int n, i = 0;
	cin >> n;
	for (i = 1; i < 370; ++i) {
		if (i * n % 360 == 0)break;
	}
	cout << i << endl;
	return 0;
}