#include <iostream>
#include <cstdio>
using namespace std;

int h, w, n;
int main() {
	cin >> h >> w >> n;
	h = max(h, w);
	cout << (n + h - 1) / h;
	return 0;
}
