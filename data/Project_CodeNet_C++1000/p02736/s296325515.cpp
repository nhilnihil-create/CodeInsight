#include <iostream>
#include <cstdio>
using namespace std;

int n, a[1000005];
string s;

int f() {
	int i, j, re=0;
	for(i=0; i<n; i++) {
		j = n - 1 - i;
		if((i^j) == i+j) re += a[i];
	}
	return re%2;
}

int main() {
	int i;
	cin >> n >> s;
	for(i=0; i<n; i++) a[i] = s[i] - '1';
	if(f()) return puts("1") * 0;
	for(i=0; i<n; i++) {
		if(a[i]==1) break;
		a[i] /= 2;
	}
	if(i<n) return puts("0") * 0;
	cout << f() * 2;
	return 0;
}