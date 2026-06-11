#include<iostream>
#include<cmath>
using namespace std;

int main() {
	double n;
	cin >> n;
	double pos = floor(n / 1.08);
	if (floor(pos * 1.08) == n) {
		cout << pos << endl;
		return 0;
	}
	if (floor((pos + 1) * 1.08) == n) {
		cout << pos + 1 << endl;
		return 0;
	}
	cout << ":(" << endl;
	return 0;
}