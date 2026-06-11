#include <iostream>

using namespace std;

int main() {
	long a, b, c, d;
	cin >> a >> b >> c >> d;
	long one = a * c;
	long two = a * d;
	long three = b * c;
	long four = b * d;
	cout << max(max(max(one, two), three), four);
}