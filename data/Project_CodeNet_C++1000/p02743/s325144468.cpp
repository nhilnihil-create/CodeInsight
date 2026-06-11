#include <iostream>
#include <cstdio>
using namespace std;

long long a, b, c, x;
int main() {
	cin >> a >> b >> c;
	x = c-a-b;
	cout << (x>0 && 4*a*b<x*x ? "Yes" : "No");
	return 0;
}
