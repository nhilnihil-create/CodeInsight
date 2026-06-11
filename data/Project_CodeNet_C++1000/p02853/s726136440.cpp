#include <iostream>
#include <cstdio>
using namespace std;

int x, y;
int main() {
	cin >> x >> y;
	cout << (max(0, 4-x) + max(0, 4-y) + (x==1 && y==1)*4) * 100000;
	return 0;
}
