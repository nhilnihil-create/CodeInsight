#include<iostream>
using namespace std;

//long int


int main() {

	long int n,i,c,flag;
	char str[1000001];
	cin >> n;
	cin >> str;
	flag = 0;
	c = 0;
	for (i = 0; i < n; i++) {
		if (str[i] == '2') {
			flag = 1;
		}
	}
	if (flag == 1) {
		for (i = 0; i < n; i++) {
			if ((str[i] == '1') || (str[i] == '3')) {
				if (((n - 1) ^ i) == (n - 1 - i)) {
					if (c == 0) { c = 1; }
					else { c = 0; }
				}
			}
		}
	}
	else {
		for (i = 0; i < n; i++) {
			if (str[i] == '3') {
				if (((n - 1) ^ i) == (n - 1 - i)) {
					if (c == 0) { c = 2; }
					else { c = 0; }
				}
			}
		}
	}
	/*
	if (flag == 1) {
		for (i = 0; i < n ; i++) {
			if ((str[i]  == '1' ) || (str[i] == '3')){
				if (i % 4 == 0) {
					if (c == 0) { c = 1; }
					else { c = 0; }
				}
				else if (i % 4 == 1) {
					if (n % 2 == 0) {
						if (c == 0) { c = 1; }
						else { c = 0; }
					}
				}
				else if (i % 4 == 2) {
					if ((n % 4 == 0) || (n % 4 == 3)) {
						if (c == 0) { c = 1; }
						else { c = 0; }
					}
				}
				else {
					if (n % 4 == 0) {
						if (c == 0) { c = 1; }
						else { c = 0; }
					}
				}
			}
		}
	}
	else {
		for (i = 0; i < n; i++) {
			if  (str[i] == '3') {
				if (i % 4 == 0) {
					if (c == 0) { c = 2; }
					else { c = 0; }
				}
				else if (i % 4 == 1) {
					if (n % 2 == 0) {
						if (c == 0) { c = 2; }
						else { c = 0; }
					}
				}
				else if (i % 4 == 2) {
					if ((n % 4 == 0) || (n % 4 == 3)) {
						if (c == 0) { c = 2; }
						else { c = 0; }
					}
				}
				else {
					if (n % 4 == 0) {
						if (c == 0) { c = 2; }
						else { c = 0; }
					}
				}
			}
		}
	}*/
	
	cout << c;

}