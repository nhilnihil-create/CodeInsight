#include <bits/stdc++.h>
using namespace std;

long long f(long long h) {
	long long r;
	if (h > 1)
		r = f(h/2)*2+1;
	else
		r = 1;
	return r;
}

int main() {
	long long h;
	cin >> h;
	cout << f(h) << endl;
}