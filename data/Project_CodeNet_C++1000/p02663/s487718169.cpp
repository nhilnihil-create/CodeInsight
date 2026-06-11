#include <iostream>
#include <cstdio>
using namespace std;

int h1, m1, h2, m2, k;
int main() {
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	m1 += h1*60;
	m2 += h2*60;
	cout << max(0, m2-m1-k);
	return 0;
}
