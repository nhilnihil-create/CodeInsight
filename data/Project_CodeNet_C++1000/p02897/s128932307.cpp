#include <iostream>
#include <cstdio>
using namespace std;

int n;
int main() {
	cin >> n;
	if(n%2==0) puts("0.500000000");
	else printf("%.9f", (n+1.0)/(2*n));
	return 0;
}
