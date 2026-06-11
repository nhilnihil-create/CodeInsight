#include <iostream>
#include <cstdio>
using namespace std;

int n, ans, fl, a[1000005];
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
	for(i=0; i<n; i++) {
		a[i] = s[i] - '1';
		if(a[i]==1) fl = 1;
	}
	if(!fl) {
		for(i=0; i<n; i++) a[i] /= 2;
	}
	ans = f();
	if(!fl) ans *= 2;
	cout << ans;
	return 0;
}