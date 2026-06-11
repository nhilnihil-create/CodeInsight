#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int x;
	cin >> x;
	int a, b, happy;
	a = x / 500;
	b = (x - 500 * a) / 5;
	happy = a * 1000 + b * 5;
	cout << happy << endl;
}