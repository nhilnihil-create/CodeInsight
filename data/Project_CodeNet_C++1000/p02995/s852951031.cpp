#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b);
long long int lcm(long long int a, long long int b); 
long long int baikan(long long int a, long long int b, long long int c);
int main() {

	//C
	long long int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << b - a + 1 - baikan(a, b, c) -  baikan(a, b, d) + baikan(a, b, lcm(c, d)) << endl;
	return 0;
	//B
	/*int n, l;
	cin >> n >> l;
	int k = n * l + n * (n - 1) / 2;
	//cout << k;
	int i;
	int min = l;
	for (i = 0; i < n; i++) {
		if (abs(l + i) < abs(min)) {
			min =  l + i;
		}
	}
	cout << k - min << endl;
	return 0;
	*/

	//A
	/*
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++) {
		if (s[i] == s[i + 1]) {
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
	return 0;
	*/
}

long long int gcd(long long int a, long long int b) {
	if (a == 0) {
		return b;
	}
	else if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
long long int lcm(long long int a, long long int b) {
	return a * b / gcd(a, b);
}
long long int baikan(long long int a, long long int b, long long int c) {
	long long int d = b - a + 1;
	if (((b - (d % c)) % c) <= (b % c)) {
		return (d - (d % c)) / c;
	}
	else {
		return (d - (d % c)) / c + 1;
	}
}