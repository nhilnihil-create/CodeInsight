#include <iostream>
using namespace std;

int h1, m1, h2, m2, k;

int main() {
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	int t1 = 60 * h1 + m1;
	int t2 = 60 * h2 + m2;
	cout << t2 - t1 - k << '\n';
}