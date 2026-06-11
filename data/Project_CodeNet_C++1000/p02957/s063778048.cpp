#include <iostream>
#include <cstdio>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	a += b;
	if(a%2) puts("IMPOSSIBLE");
	else cout << a/2;
	return 0;
}
