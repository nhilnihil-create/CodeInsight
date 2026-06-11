#include <iostream>
#include <cstdio>
using namespace std;

int a, b, c;
int main() {
	cin >> a >> b >> c;
	cout << (a+b+c<=21 ? "win" : "bust");
	return 0;
}
