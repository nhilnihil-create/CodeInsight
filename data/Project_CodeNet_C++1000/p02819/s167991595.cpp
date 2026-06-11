#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
bool prime(int n) {
	if (n == 1)return false;
	if (n == 2)return true;
	if (n == 3)return true;
	if (n == 4)return false;
	for (int i = 2; i < ceil(sqrt(n)); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = n;; i++) {
		if (prime(i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}