#include <iostream>
#include <cstdio>
using namespace std;

int n, r;
int main() {
	cin >> n >> r;
	cout << r + 100 * max(0, 10-n);
	return 0;
}
