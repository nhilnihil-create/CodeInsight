#include <iostream>
#include <cstdio>
using namespace std;

int a, b, c;
int main() {
	cin >> a >> b >> c;
	if(a==b && b==c) puts("No");
	else if(a==b || b==c || c==a) puts("Yes");
	else puts("No");
	return 0;
}
