#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int a, b, p, o, i, u;
	char t;
	while (1){
		cin >> a >> t  >> b;
		if (t == '+') {
			p = a + b;
			cout << p << endl;
		}
		else if (t == '-') {
			p = a - b;
			cout << p << endl;
		}
		else if (t == '/') {
			p = a / b;
			cout << p << endl;
		}
		else if (t == '*') {
			p = a*b;
			cout << p << endl;
		}
		else if (t == '?')
			break;
	}
	return 0;
	
}