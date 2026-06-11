// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long maxs = 1e9;

long long n, k, s, rest;

int main() {
	cin >> n >> k >> s;
	for (int i=0; i<k; i++) {
		cout << s << ' ';
	}
	if (s == maxs)
		rest = maxs - 1;
	else
		rest = maxs;
	for (int i=0; i<n-k; i++) {
		cout << rest << ' ';
	}
}